//
//  blocks.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/18.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#include "blocks.hpp"

//ブロックのクラス。
Block::Block(){
	//コンストラクタ
	//変数初期化
	pos_x = 0.0;
	pos_y = 20.0;
	pos_z = 0.0;
	canMove = true;
	
	block_type = rand() % 8;	//8種類
	std::cout << "Type " << block_type << " block is created." <<std::endl;
}

Block::Block(int block_n){
	//デバッグ用？コンストラクタ
	Block();
	if ((block_n<8) && (block_n>0)){
		block_type = block_n;
		std::cout << "Type " << block_type << " block is created." <<std::endl;
	}else{
		std::cerr << "ERROR : block type none (int block_n = " << block_n << ")." << std::endl;
		exit(1);
	}
}

Block::~Block(){
	//デストラクタ
	std::cerr << "block is destructed." << std::endl;
	
}

void Block::draw(){
	//displayのループ中で呼び出し。
	//できるだけ早くしたいので、行列を作成して呼び出す形式が良い。
	//（switch文が重そうなので、コンストラクタに格納しておく。）
	glPushMatrix();
	glTranslated(pos_x, pos_y, pos_z);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glutSolidCube(1.0);
//	glTranslated(1.0, 0.0, 0.0);
//	glutSolidCube(1.0);
//	glTranslated(1.0, 0.0, 0.0);
//	glutSolidCube(1.0);
//	glTranslated(1.0, 0.0, 0.0);
//	glutSolidCube(1.0);
	glPopMatrix();
}

void Block::move(unsigned int direction){
	//std::cout << "move called" << std::endl;
	if (canMove){
		switch (direction) {
			case 0:
				pos_x += 1.0;
				break;
			case 1:
				pos_x -= 1.0;
				break;
			case 2:
				pos_y += 1.0;
				break;
			case 3:
				pos_y -= 1.0;
				break;
			case 4:
				pos_z += 1.0;
				break;
			case 5:
				pos_z -= 1.0;
				break;

			default:
				std::cerr << "ERROR : block direction none (int direction = " << direction << ")." << std::endl;
				exit(1);
				break;
		}
	}else{
		std::cout << "can't move " << direction << " ." << std::endl;
	}
}

void Block::return_position(){
	std::cout << pos_x << "," << pos_y << "," << pos_z << std::endl;
}

void Block::drop(){
	pos_y -= 1.0;
	if (pos_y < 0.0){
		pos_y = 0.0;
		canMove = false;
	}else{
		std::cout << "dropped " << std::endl;
	}
}

Block obj;

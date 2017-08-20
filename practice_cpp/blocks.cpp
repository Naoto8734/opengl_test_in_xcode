//
//  blocks.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/18.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#include "blocks.hpp"

const GLdouble Block::vertex[][3] = {
	{ -1.0, 0.0, -1.0 }, /* A */
	{  1.0, 0.0, -1.0 }, /* B */
	{  1.0, 1.0, -1.0 }, /* C */
	{ -1.0, 1.0, -1.0 }, /* D */
	{ -1.0, 0.0,  1.0 }, /* E */
	{  1.0, 0.0,  1.0 }, /* F */
	{  1.0, 1.0,  1.0 }, /* G */
	{ -1.0, 1.0,  1.0 }  /* H */
};

const int Block::face[][4] = {
	{ 0, 1, 2, 3 },
	{ 1, 5, 6, 2 },
	{ 5, 4, 7, 6 },
	{ 4, 0, 3, 7 },
	{ 4, 5, 1, 0 },
	{ 3, 2, 6, 7 }
};

const GLdouble Block::normal[][3] = {
	{ 0.0, 0.0,-1.0 },
	{ 1.0, 0.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{-1.0, 0.0, 0.0 },
	{ 0.0,-1.0, 0.0 },
	{ 0.0, 1.0, 0.0 }
};

const GLdouble Block::pos_limit = 8.0;

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
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
	glFrontFace(GL_CW);
	glBegin(GL_LINES);
	for (int j = 0; j < 6; ++j) {
		//glNormal3dv(normal[j]);
		for (int i = 0; i < 4; ++i) {
			glVertex3dv(vertex[face[j][i]]);
		}
	}
	glEnd();
	glFrontFace(GL_CCW);
	glPopMatrix();
}

void Block::move(unsigned int direction){
	//std::cout << "move called" << std::endl;
	if (canMove){
		switch (direction) {
			case 0:
				pos_x += 1.0;
				if (pos_x > pos_limit)pos_x = pos_limit;
				break;
			case 1:
				pos_x -= 1.0;
				if (pos_x < -pos_limit)pos_x = -pos_limit;
				break;
			case 2:
				pos_y += 1.0;
				if (pos_y > pos_limit)pos_y = pos_limit;
				break;
			case 3:
				pos_y -= 1.0;
				if (pos_y < -pos_limit)pos_y = -pos_limit;
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

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
	block_type = rand() % 8;	//8種類
	std::cout << "Type " << block_type << " block is created." <<std::endl;
}

Block::Block(int block_n){
	//デバッグ用？コンストラクタ
	if ((block_n<8) && (block_n>0)){
		block_type = block_n;
		std::cout << "Type " << block_type << " block is created." <<std::endl;
	}else{
		std::cerr << "ERROR : block type none" << std::endl;
		exit(1);
	}
}

Block::~Block(){
	//デストラクタ
	std::cerr << "block is destructed." << std::endl;
	
}

void Block::draw(){
	//displayのループ中で呼び出し。
	glPushMatrix();
	glTranslated(xd, yd, zd);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glutSolidCube(1.0);
	glPopMatrix();
}

Block blocks_obj[] = {};

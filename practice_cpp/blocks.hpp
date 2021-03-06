//
//  blocks.hpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/18.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#ifndef blocks_hpp
#define blocks_hpp

#ifndef assist_funcs_hpp
#include "assist_funcs.hpp"
#endif
//ブロックの作成。クラス。

class Block{
private:
	static const GLdouble vertex[][3];
	static const int face[][4];
	static const GLdouble normal[][3];
	static const GLdouble pos_limit;
	int block_type;	//0~7までの8種類。
	GLdouble pos_x;	//ブロックの座標
	GLdouble pos_y;
	GLdouble pos_z;
	bool canMove;
public:
	Block();	//コンストラクタ
	Block(int block_n);	//コンストラクタのオーバーライド。デバッグ用。
	~Block();	//デストラクタ
	void draw();
	void move(unsigned int direction);
	void drop();
	void return_position();
};

extern Block obj;


#endif /* blocks_hpp */

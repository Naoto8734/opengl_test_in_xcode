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
	int block_type;//0~7までの8種類。
public:
	Block();	//コンストラクタ
	Block(int block_n);	//コンストラクタのオーバーライド。デバッグ用。
	~Block();	//デストラクタ
	void draw();
};

extern Block blocks_obj[];
#endif /* blocks_hpp */

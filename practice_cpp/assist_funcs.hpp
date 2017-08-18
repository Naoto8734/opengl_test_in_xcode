//
//  assist_funcs.hpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/18.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#ifndef assist_funcs_hpp
#define assist_funcs_hpp

//基本的にここでインクルード。
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <time.h>	//乱数の初期化用
#include "blocks.hpp"

//グローバル変数
extern double xd;
extern double yd;
extern double zd;
extern const GLfloat red[];

//プロトタイプ宣言
void init();	//コールバック関数群
void display();
void close();
void reshape(int x, int y);
void keyboard(unsigned char key, int x, int y);
void keyboardup(unsigned char key, int x, int y);
void timer(int value);
//文字の描画について。

#endif /* assist_funcs_hpp */

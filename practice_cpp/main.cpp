//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#include "assist_funcs.hpp"

//グローバル変数宣言
const char game_title[] = "ziggurat";


int main(int argc, char *argv[]){
	glutInit(&argc, argv);	//glutの初期化
	srand((unsigned int)time(NULL));	//乱数の初期化
	
	//windowの作成
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);	//バッファの初期化
	glutInitWindowSize(500, 500);
	glutCreateWindow(game_title);
	
	//コールバック関数
	glutDisplayFunc(display);
	glutWMCloseFunc(close);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardup);
	glutTimerFunc(17, timer, 0);
	
	//初期化
	init();
	
	glutMainLoop();//終了はexitで行う
	
	return 0;
}

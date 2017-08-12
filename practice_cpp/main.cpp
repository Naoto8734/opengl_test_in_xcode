//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/07/22.
//  Copyright © 2017年 NYamashita. All rights reserved.
//
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

void display(void){
	//レンダリング関数。レンダリング時に呼び出される。
	glClear(GL_COLOR_BUFFER_BIT);	//全ピクセルのクリア
	glColor3f(1.0, 1.0, 1.0);	//白
	glBegin(GL_POLYGON);	//ポリゴン描画開始
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glFlush();	//バッファリングされたopenglのルーチンを開始
}

void init(void){
	glClearColor(0.0, 1.0, 0.0, 0.0);	//緑でクリア
	glMatrixMode(GL_PROJECTION);	//視野に関する値を初期化
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/*
void setup(void) {

}

void draw(void) {

}


void resize(int width, int height) {

}
*/
int main(int argc, char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("This is window title");
	init();
	glutDisplayFunc(display);	//コールバック関数の登録
	glutMainLoop();
	return 0;
}

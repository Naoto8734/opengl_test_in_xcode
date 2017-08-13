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

void init(void){
	glClearColor(0.0, 0.8, 0.0, 0.0);	//緑でクリア
	glShadeModel(GL_FLAT);
}

void display(void){
	//レンダリング関数。レンダリング時に呼び出される。
	glClear(GL_COLOR_BUFFER_BIT);	//全ピクセルのクリア
	glColor3f(1.0, 1.0, 1.0);	//白
	glLoadIdentity();	//行列のクリア
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);	//視野変換
	glScalef(1.0, 2.0, 1.0);
	glutWireTeapot(1);
	glFlush();
}

void reshape(int w, int h){
	//ウィンドウサイズ変更時のコールバック関数
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);	//コールバック関数の登録
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

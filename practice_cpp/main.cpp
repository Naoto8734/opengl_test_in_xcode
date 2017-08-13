//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/07/22.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

/*-----------------------------------------------------------------------------------*
 * インクルード
 *-----------------------------------------------------------------------------------*/

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

/*-----------------------------------------------------------------------------------*
 * グローバル変数
 *-----------------------------------------------------------------------------------*/
int window_width = 320;
int window_height = 240;
const char GAME_TITLE[] = "Ziggurat";

/*-----------------------------------------------------------------------------------*
 * 関数のプロトタイプ宣言
 *-----------------------------------------------------------------------------------*/
void Init(void);
void Display(void);
void Reshape(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Close();

/*-----------------------------------------------------------------------------------*
 * コールバック関数
 *-----------------------------------------------------------------------------------*/

void Init(void){
	glClearColor(0.0, 0.6, 0.0, 0.0);	//黒や白より更新がわかりやすいので、緑でクリア。
}

void Display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POLYGON);
	glColor3d(1.0, 0.0, 0.0);
	glVertex2d(-0.9, -0.9);
	glColor3d(0.0, 1.0, 0.0);
	glVertex2d(0.9, -0.9);
	glColor3d(0.0, 0.0, 1.0);
	glVertex2d(0.9, 0.9);
	glColor3d(1.0, 1.0, 0.0);
	glVertex2d(-0.9, 0.9);
	glEnd();
	
	glFlush();
}

void Reshape(int w, int h){
	window_width = w;
	window_height = h;
	
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glLoadIdentity();
	glOrtho(-0.5, (GLdouble)w-0.5, (GLdouble)h-0.5, -0.5, -1.0, 1.0);
}

void Keyboard(unsigned char key, int x, int y){
	std::cout << key << " key is press.\n";
	switch ( key ){
		case 0x71:	//q
			Close();
			break;
	}
}

void KeyboardUp(unsigned char key, int x, int y){
	std::cout << key << " key is released.\n";
}

void Mouse(int button, int state, int x, int y){
	static int x0, y0;
	switch (button) {
		case GLUT_LEFT_BUTTON:
			//std::cout << "left";
			if (state == GLUT_UP) {
				/* ボタンを押した位置から離した位置まで線を引く */
				glColor3d(0.0, 0.0, 0.0);
				glBegin(GL_LINES);
				glVertex2i(x0, y0);
				glVertex2i(x, y);
				glEnd();
				glFlush();
			}
			else {
				/* ボタンを押した位置を覚える */
				x0 = x;
				y0 = y;
			}
			break;
		case GLUT_MIDDLE_BUTTON:
			//std::cout << "middle";
			Display();
			break;
		case GLUT_RIGHT_BUTTON:
			//std::cout << "right";
			if (state == GLUT_UP) {
				/* ボタンを押した位置から離した位置まで線を引く */
				glColor3d(1.0, 1.0, 1.0);
				glBegin(GL_POLYGON);
				glVertex2i(x0, y0);
				glVertex2i(x0, y);
				glVertex2i(x, y);
				glVertex2i(x, y0);
				glEnd();
				glFlush();
			}
			else {
				/* ボタンを押した位置を覚える */
				x0 = x;
				y0 = y;
			}
			break;
		default:
			break;
	}
	/*
	std::cout << " button is ";
	switch (state) {
		case GLUT_UP:
			std::cout << "up";
			break;
		case GLUT_DOWN:
			std::cout << "down";
			break;
		default:
			break;
	}
	std::cout << " at " << x <<","<< y << std::endl;*/
}

void Close(){
	std::cout << "Finish game.\n";
	exit(0);
}

/*-----------------------------------------------------------------------------------*
 * メインループ
 *-----------------------------------------------------------------------------------*/
int main(int argc, char * argv[]) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(window_width, window_height);
	glutCreateWindow(GAME_TITLE);
	
	Init();
	
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutWMCloseFunc(Close);
	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(KeyboardUp);
	glutMouseFunc(Mouse);
	
	glutMainLoop();
	
	return 0;
}

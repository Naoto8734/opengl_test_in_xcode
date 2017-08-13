//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/07/22.
//  Copyright © 2017年 NYamashita. All rights reserved.
//
/*-----------------------------------------------------------------------------------*
 * 定数宣言
 *-----------------------------------------------------------------------------------*/
#define MAXPOINTS 100

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
GLint point[MAXPOINTS][2];
int point_num = 0;
int rubber_band = 0;

/*-----------------------------------------------------------------------------------*
 * 関数のプロトタイプ宣言
 *-----------------------------------------------------------------------------------*/
void Init(void);
void Display(void);
void Reshape(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Motion(int x, int y);
void Close();

/*-----------------------------------------------------------------------------------*
 * コールバック関数
 *-----------------------------------------------------------------------------------*/

void Init(void){
	glClearColor(0.0, 0.6, 0.0, 0.0);	//黒や白より更新がわかりやすいので、緑でクリア。
}

void Display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	if (point_num>1) {
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		for (int i = 0; i < point_num; i++) {
			glVertex2iv(point[i]);
		}
		glEnd();
	}
	
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
		case 'q':
		case 'Q':
		case 0x1b:
			Close();
			break;
	}
}

void KeyboardUp(unsigned char key, int x, int y){
	std::cout << key << " key is released.\n";
}

void Mouse(int button, int state, int x, int y){
	point[point_num][0] = x;
	point[point_num][1] = y;
	switch (button) {
		case GLUT_LEFT_BUTTON:
			//std::cout << "left";
			if (state == GLUT_UP) {
				glColor3d(1.0, 1.0, 1.0);//ボタンを押した位置から線を引く
				glBegin(GL_LINES);
				glVertex2iv(point[point_num-1]);
				glVertex2iv(point[point_num]);
				glEnd();
				glFlush();
			}
			if (point_num < MAXPOINTS +1) point_num++;
			break;
		case GLUT_MIDDLE_BUTTON:
			//std::cout << "middle";
			Display();
			break;
		case GLUT_RIGHT_BUTTON:
			//std::cout << "right";
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

void Motion(int x, int y){
	static GLint prev_point[2];
	
	glEnable(GL_COLOR_LOGIC_OP);
	glLogicOp(GL_INVERT);
	
	glBegin(GL_LINES);
	if (rubber_band){
		//以前のラバーバンドの消去
		glVertex2iv(point[point_num-1]);
		glVertex2iv(prev_point);
	}
	glVertex2iv(point[point_num-1]);
	glVertex2i(x, y);
	glEnd();
	glFlush();
	
	glLogicOp(GL_COPY);
	glDisable(GL_COLOR_LOGIC_OP);
	
	prev_point[0] = x;
	prev_point[1] = y;
	
	rubber_band = 1;
	
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
	glutMotionFunc(Motion);
	
	glutMainLoop();
	
	return 0;
}

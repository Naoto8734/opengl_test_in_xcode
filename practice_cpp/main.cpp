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

/*-----------------------------------------------------------------------------------*
 * インクルード
 *-----------------------------------------------------------------------------------*/
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include "cube.hpp"
#include "grobal_variables.hpp"

/*-----------------------------------------------------------------------------------*
 * グローバル変数
 *-----------------------------------------------------------------------------------*/
int window_height = 500;
int window_width = 500;
const char GAME_TITLE[] = "Ziggurat";

GLdouble vertex[][3] = {
	{ 0.0, 0.0, 0.0 },
	{ 1.0, 0.0, 0.0 },
	{ 1.0, 1.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 0.0, 1.0 },
	{ 1.0, 1.0, 1.0 },
	{ 0.0, 1.0, 1.0 }
};
/*
int edge[][2] = {
	{ 0, 1 },
	{ 1, 2 },
	{ 2, 3 },
	{ 3, 0 },
	{ 4, 5 },
	{ 5, 6 },
	{ 6, 7 },
	{ 7, 4 },
	{ 0, 4 },
	{ 1, 5 },
	{ 2, 6 },
	{ 3, 7 }
};*/

int face[][4] = {
	{ 0, 1, 2, 3 },
	{ 1, 5, 6, 2 },
	{ 5, 4, 7, 6 },
	{ 4, 0, 3, 7 },
	{ 4, 5, 1, 0 },
	{ 3, 2, 6, 7 }
};
/*
GLdouble color[][3] = {
	{ 1.0, 0.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 1.0, 0.0 },
	{ 1.0, 0.0, 1.0 },
	{ 0.0, 1.0, 1.0 }
};*/

GLdouble normal[][3] = {
	{ 0.0, 0.0,-1.0 },
	{ 1.0, 0.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{-1.0, 0.0, 0.0 },
	{ 0.0,-1.0, 0.0 },
	{ 0.0, 1.0, 0.0 }
};

GLfloat light0pos[] = { 0.0, 3.0, -4.0, 1.0 };
GLfloat light1pos[] = { 5.0, 3.0, 0.0, 1.0 };

GLfloat red[] = {0.8, 0.2, 0.2, 1.0};
GLfloat blue[] = {0.2, 0.2, 1.0, 1.0};
GLfloat yellow[] = {0.8, 0.8, 0.1, 1.0};

/*-----------------------------------------------------------------------------------*
 * 関数のプロトタイプ宣言
 *-----------------------------------------------------------------------------------*/
//コールバッック関数
void Init(void);
void Idle(void);
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
	glClearColor(0.1, 0.7, 0.1, 0.0);	//黒や白より更新がわかりやすいので、緑でクリア。
	
	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, yellow);
	glLightfv(GL_LIGHT1, GL_SPECULAR, blue);
}


void Idle(void)
{
	glutPostRedisplay();
}

void Display(void){
	static int r = 0;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
	glLightfv(GL_LIGHT1, GL_POSITION, light1pos);
	glPushMatrix();
	
	glRotated((double)r, 1.0, -1.0, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
	
	glutSolidSphere(1.0, 32.0, 16.0);
	glPushMatrix();
	glTranslated(1.0, 1.0, 1.0);
	glRotated((double)(r * 2), 1.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
	Cube();
	glPopMatrix();
	glPopMatrix();
	
	glutSwapBuffers();
	
	if (++r >= 360) r = 0;
}

void Reshape(int w, int h){
	window_width = w;
	window_height = h;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, 1.0, 1.0, 100.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void Keyboard(unsigned char key, int x, int y){
	//std::cout << key << " key is press at " << x << " , " << y << "\n";
	switch ( key ){
		case 'Q':
		case 'q':
			Close();
			break;
		default:
			break;
	}
}

void KeyboardUp(unsigned char key, int x, int y){
	//std::cout << key << " key is released at " << x << " , " << y << "\n";
}

void Mouse(int button, int state, int x, int y){
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) {
				glutIdleFunc(Idle);
			}
			//std::cout << "left";
			break;
		case GLUT_MIDDLE_BUTTON:
			if (state == GLUT_DOWN){
				glutPostRedisplay();
			}
			//std::cout << "middle";
			break;
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN) {
				glutIdleFunc(0);
			}
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
	//std::cout << "Drag : "<< x << " , " << y <<"\n";
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
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
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

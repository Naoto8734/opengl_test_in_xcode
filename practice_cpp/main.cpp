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

/*-----------------------------------------------------------------------------------*
 * 関数のプロトタイプ宣言
 *-----------------------------------------------------------------------------------*/
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
	glClearColor(0.0, 0.6, 0.0, 0.0);	//黒や白より更新がわかりやすいので、緑でクリア。
	
	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}


void Idle(void)
{
	glutPostRedisplay();
}

void Display(void){
	static int r = 0;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotated((double)r, 1.0, -1.0, 0.0);
	
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; i++) {
		//glNormal3dv(color[i]);
		glNormal3dv(normal[i]);
		for (int j = 0; j < 4; j++) {
			glVertex3dv(vertex[face[i][j]]);
		}
	}
	glEnd();
	
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

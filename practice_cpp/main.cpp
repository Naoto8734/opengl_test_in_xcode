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

static GLfloat spin = 0.0;	//係数

void init(void){
	glClearColor(0.0, 1.0, 0.0, 0.0);	//緑でクリア
	glShadeModel(GL_FLAT);
}

void display(void){
	//レンダリング関数。レンダリング時に呼び出される。
	glClear(GL_COLOR_BUFFER_BIT);	//全ピクセルのクリア
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);	//白
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();
	glutSwapBuffers();
}

void spinMatrix(void){
	spin = spin + 2.0;
	if (spin > 360.0) {
		spin -= 360.0;
	}
	glutPostRedisplay();
}

void reshape(int w, int h){
	//ウィンドウサイズ変更時のコールバック関数
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
	//マウス用コールバック関数
	switch (button){
			case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) glutIdleFunc(spinMatrix);
			break;
			
			case GLUT_MIDDLE_BUTTON:
			if  (state == GLUT_DOWN) glutIdleFunc(NULL);
			break;
			
			default:
			break;
	}
}

int main(int argc, char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);	//コールバック関数の登録
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

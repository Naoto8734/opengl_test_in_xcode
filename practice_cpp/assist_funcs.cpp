//
//  assist_funcs.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/18.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#include "assist_funcs.hpp"

//文字の描画について。

//変数宣言
static const GLfloat ground[][4] = {
	{ 0.6, 0.6, 0.6, 1.0 },
	{ 0.3, 0.3, 0.3, 1.0 }
};
const GLfloat red[] = {0.8, 0.1, 0.1, 1.0};
static const GLfloat pos0[] = {0.0, 25.0, 3.0, 1.0};
static const GLfloat pos1[] = {0.0, 25.0, -3.0, 1.0};
int block_num  = 0;
static int timer_sec = 17;
static GLdouble rot;

void init(){
	glClearColor(0.1, 0.6, 0.1, 1.0);	//緑でクリア
	glEnable(GL_DEPTH_TEST);
	
	
	glEnable(GL_LIGHTING);//ライト
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void display(){
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	//行列の初期化
	
	gluLookAt(3.0, 25.0, 5.0,
			  0.0, 0.0, 1.0,
			  0.0, 1.0, 0.0);	//視野変換
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	
	glRotated(rot, 0.0, 1.0, 0.0);
	
	//モデリング変換
	//地面の描画
	glBegin(GL_QUADS);
	glNormal3d(0.0, 1.0, 0.0);
	for (int j = -5; j < 5; ++j) {
		for (int i = -5; i < 5; ++i) {
			glMaterialfv(GL_FRONT, GL_DIFFUSE, ground[(i + j) & 1]);
			glVertex3d((GLdouble)i, -0.5, (GLdouble)j);
			glVertex3d((GLdouble)i, -0.5, (GLdouble)(j + 1));
			glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)(j + 1));
			glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)j);
		}
	}
	glEnd();
	
	obj.draw();
	
	glutSwapBuffers();
}

void close(){
	std::cout << "Game end." << std::endl;
	exit(0);
}

void reshape(int x, int y){
	//ビューポート変換
	glViewport(0.0, 0.0, (GLsizei)x, (GLsizei)y);
	//	if (x<y){
	//		glViewport(0.0, 0.0, (GLsizei)x, (GLsizei)x);
	//	}else{
	//		glViewport(0.0, 0.0, (GLsizei)y, (GLsizei)y);
	//	}
	
	//投影変換
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	//gluPerspective(45, (double)y/(double)x, 0.1, 1000);
	gluPerspective(45, 1, 0.1, 1000);
	
	//モデリング変換&視野変換
}

void keyboard(unsigned char key, int x, int y){
	//std::cout << key << " is pressed." << std::endl;
	switch ( key ){
		case '\033':	//Esc
		case 'q':
		case 'Q':
			close();
			break;
			
		case 'i':
			obj.move(0);
			break;
		case 'k':
			obj.move(1);
			break;
			
		case 'j':
			obj.move(4);
			break;
		case 'l':
			obj.move(5);
			break;
			
		case 'u':
			break;
		case 'o':
			break;
			
		case 'f':
			break;
			
		case 'g':
			break;
			
		case 0x20:	//スペースキー
			obj.return_position();
			break;
			
		default:
			break;
	}
}

void keyboardup(unsigned char key, int x, int y){
	//std::cout << key << " is released." << std::endl;
}

void timer(int value){
	static int ticks;
	glutTimerFunc(timer_sec, timer, 0);
	display();
	rot += 0.1;
	if (ticks > 1000){
		obj.drop();
		ticks = 0;
	}else{
		ticks += timer_sec;
	}
}

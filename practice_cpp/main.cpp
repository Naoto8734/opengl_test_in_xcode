//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

static double ex = 0.0, ez = 0.0; /* 視点の位置 */
static double r = 0.0;            /* 視点の向き */
static double Vx, Vz, Re = 0.0;
static double Cd = 0.9;
static int window_width = 500;
static int window_height = 500;
static double t = 0.01;
static const int TIMER_WAIT = 33;

//プロトタイプ宣言
void scene(void);
void display(void);
void resize(int w, int h);
void close(void);
void keyboard(unsigned char key, int x, int y);
void init(void);
void mouse(int x, int y);
void timer(int value);
void click(int button, int state, int x, int y);


void scene(void){
	static GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 };
	static GLfloat green[] = { 0.2, 0.8, 0.2, 1.0 };
	static GLfloat blue[] = { 0.2, 0.2, 0.8, 1.0 };
	static GLfloat yellow[] = { 0.8, 0.8, 0.2, 1.0 };
	static GLfloat ground[][4] = {
		{ 0.6, 0.6, 0.6, 1.0 },
		{ 0.3, 0.3, 0.3, 1.0 }
	};
	
	
	// 赤い箱
	glPushMatrix();
	glTranslated(0.0, 0.0, -3.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glutSolidCube(1.0);
	glPopMatrix();
	
	// 緑の箱
	glPushMatrix();
	glTranslated(0.0, 0.0, 3.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	glutSolidCube(1.0);
	glPopMatrix();
	
	// 青い箱
	glPushMatrix();
	glTranslated(-3.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
	glutSolidCube(1.0);
	glPopMatrix();
	
	// 黄色い箱
	glPushMatrix();
	glTranslated(3.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glutSolidCube(1.0);
	glPopMatrix();
	
	// 地面
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
}

void display(void)
{
	static GLfloat lightpos[] = { 3.0, 4.0, 5.0, 1.0 }; /* 光源の位置 */

	/* 画面クリア */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	/* モデルビュー変換行列の初期化 */
	glLoadIdentity();
	
	/* 視点の移動 */
	if (r < 0){
		r += 360.0;
	}
	r = fmod(r, 360.0);
	
	glRotated(r, 0.0, 1.0, 0.0);
	glTranslated(ex, 0.0, ez);
	
	/* 光源の位置を設定 */
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	
	/* シーンの描画 */
	scene();
	
	glutSwapBuffers();
}

void resize(int w, int h)
{
	window_width = w;
	window_height = h;
	
	/* ウィンドウ全体をビューポートにする */
	glViewport(0, 0, w, h);
	
	/* 透視変換行列の指定 */
	glMatrixMode(GL_PROJECTION);
	
	/* 透視変換行列の初期化 */
	glLoadIdentity();
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
	
	/* モデルビュー変換行列の指定 */
	glMatrixMode(GL_MODELVIEW);
}

void close(void){
	std::cout << "End game." << std::endl;
	exit(0);
}

void keyboard(unsigned char key, int x, int y)
{
	/* ESC か q をタイプしたら終了 */
	switch (key) {
		case 'q':
		case 'Q':
		case 0x1b:
			close();
			break;
		case 0x20:
			ex = 0;
			ez = 0;
			r = 0;
			break;
		default:
			break;
	}
	display();
}


void init(void)
{
	/* 初期設定 */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void mouse(int x, int y) {
	double x_d, y_d ,r_d = 0.0;
	
	x_d = -(double)(x*2)/(double)window_width + 1.0;
	y_d = -(double)(y*2)/(double)window_height + 1.0;
	r_d = -atan(y_d/x_d)*180/M_PI*0.1;
	
	Vx = Vx + x_d;
	Vz = Vz + y_d;
	Re = Re + r_d;

	std::cout << x_d << " , " << y_d << " , " << r_d << std::endl;
}

void click(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN){
			Cd = 1.0;
		}else{
			Cd = 0.9;
		}
	}
}

void timer(int value){
	glutTimerFunc( TIMER_WAIT, timer, 0);
	Vx = Vx * Cd;
	Vz = Vz * Cd;
	Re = Re * Cd;
	ex = ex + Vx * t;
	ez = ez + Vz * t;
	r = r + Re * t;
	//std::cout << ex << " , " << ez << " , " << r << std::endl;
	display();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(window_width, window_height);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutWMCloseFunc(close);
	glutMouseFunc(click);
	glutMotionFunc(mouse);
	glutTimerFunc( TIMER_WAIT, timer, 0);
	init();
	glutMainLoop();
	return 0;
}


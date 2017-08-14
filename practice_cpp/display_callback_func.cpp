//
//  display_callback_func.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#include "display_callback_func.hpp"

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

void Close(){
	std::cout << "Finish game.\n";
	exit(0);
}

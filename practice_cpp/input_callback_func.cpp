//
//  input_callback_func.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#include "input_callback_func.hpp"
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

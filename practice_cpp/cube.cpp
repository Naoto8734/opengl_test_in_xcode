//
//  cube.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#include "cube.hpp"

//その他
void Cube(void) {
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; i++) {
		//glNormal3dv(color[i]);
		glNormal3dv(normal[i]);
		for (int j = 0; j < 4; j++) {
			glVertex3dv(vertex[face[i][j]]);
		}
	}
	glEnd();
}

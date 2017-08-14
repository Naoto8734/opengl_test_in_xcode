//
//  grobal_variables.hpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#ifndef grobal_variables_h
#define grobal_variables_h

#ifndef OpenGL_OpenGL_h
#include <OpenGL/OpenGL.h>
#endif

#ifndef GLUT_GLUT_h
#include <GLUT/GLUT.h>
#endif

extern int window_height;
extern int window_width;
extern const char GAME_TITLE[];

extern GLdouble vertex[][3];

//extern int edge[][2];

extern int face[][4];

//extern GLdouble color[][3];

extern GLdouble normal[][3];

extern GLfloat light0pos[];
extern GLfloat light1pos[];

extern GLfloat red[];
extern GLfloat blue[];
extern GLfloat yellow[];

#endif /* grobal_variables_h */

//
//  input_callback_func.hpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#ifndef input_callback_func_hpp
#define input_callback_func_hpp

#ifndef iostream
#include <iostream>
#endif

#ifndef OpenGL_OpenGL_h
#include <OpenGL/OpenGL.h>
#endif

#ifndef GLUT_GLUT_h
#include <GLUT/GLUT.h>
#endif

#ifndef grobal_variables_hpp
#include "grobal_variables.hpp"
#endif

#ifndef display_callback_func_hpp
#include "display_callback_func.hpp"
#endif

void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Motion(int x, int y);

#endif /* input_callback_func_hpp */

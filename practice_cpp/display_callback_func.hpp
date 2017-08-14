//
//  display_callback_func.hpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#ifndef display_callback_func_hpp
#define display_callback_func_hpp

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

#ifndef input_callback_func_hpp
#include "input_callback_func.hpp"
#endif

#ifndef cube_hpp
#include "cube.hpp"
#endif

void Init(void);
void Idle(void);
void Display(void);
void Reshape(int w, int h);
void Close();

#endif /* display_callback_func_hpp */

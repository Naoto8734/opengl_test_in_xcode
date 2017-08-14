//
//  test_ass.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#include "test_ass.hpp"
#include <iostream>

void myclass::set_a(int num){
	myclass::myprivate_a = num;
}

int myclass::get_a(){
	return myclass::myprivate_a;
}

myclass::myclass(){
	std::cout << "This is myclass's constructor.\n";
}

myclass::~myclass(){
	std::cout << "This is myclass's destructor.\n";
}

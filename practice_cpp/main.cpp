//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/07/22.
//  Copyright © 2017年 NYamashita. All rights reserved.
//
#include <iostream>
#include "test_ass.hpp"

int main(int argc, char * argv[]) {
	myclass obj1;
	
	obj1.set_a(100);
	
	std::cout << obj1.get_a() << std::endl;
	return 0;
}

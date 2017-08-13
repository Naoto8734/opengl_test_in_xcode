//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/07/22.
//  Copyright © 2017年 NYamashita. All rights reserved.
//
#include <iostream>

int main(int argc, char * argv[]) {
	int i = 0;
	char string[80];
	std::cout << "整数と文字列を入力してください。\n";
	std::cin >> i >> string;
	std::cout << "入力された数字は" << i << "です。\n文字列は" << string << "です。\n";
	return 0;
}

//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/07/22.
//  Copyright © 2017年 NYamashita. All rights reserved.
//
#include <iostream>
#include <fstream>

static const std::string HOME_DIR = "/Users/naoto/Documents/swift_xcode/practice_cpp/practice_cpp/";

int main(int argc, char * argv[]) {
	//ファイル入出力の基本
	
	//ファイルの作成
	std::ofstream fout(HOME_DIR+"hello.txt");
	
	if (!fout){
		std::cout << "出力ファイルが開けません";
		return 1;
	}
	
	fout << "Hello world!\n";
	fout << 114514 << "\n";
	fout.close();
	
	//ファイルの読み込み
	std::ifstream fin(HOME_DIR+"hello.txt");
	
	if (!fin){
		std::cout << "入力ファイルが読み込めません";
		return 1;
	}
	
	char str[80];
	int i;
	
	fin >> str ;
	std::cout << str << " " << i << std::endl;
	
	fin.close();
	
	return 0;
}

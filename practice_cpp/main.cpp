//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/07/22.
//  Copyright © 2017年 NYamashita. All rights reserved.
//
#include <iostream>

class myclass {
	//非公開関数、非公開変数。
	int a;

public:
	//公開関数、変数。
	void set_a(int num);
	int get_a();
	int b;
};

void myclass::set_a(int num){
	a = num;
}

int myclass::get_a(){
	return a;
}

int main(int argc, char * argv[]) {
	myclass myobj1, myobj2;
	
	myobj1.set_a(114);
	myobj2.set_a(514);
	
	std::cout << myobj1.get_a() << "\n";
	std::cout << myobj2.get_a() << "\n";
	
	myobj1.b = 810;
	myobj2.b = 931;
	
	std::cout << myobj1.b + myobj2.b << "\n";
	
	return 0;
}

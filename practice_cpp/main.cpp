//
//  main.cpp
//  practice_cpp
//
//  Created by Naoto on 2017/07/22.
//  Copyright © 2017年 NYamashita. All rights reserved.
//
#include <iostream>

int main(int argc, char * argv[]) {
	//素数判定プログラム
	int MAX = 0;
	std::cout << "素数を判定します。\n最大値を入力してください。\n";
	std::cin >> MAX;
	std::cout << MAX << "までの素数を判別します。\n";
	for (int i = 1; i <= MAX; i++){
		//約数を数える。
		int divisor = 0;
		for (int j = 1; j <= i; j ++) {
			//std::cout << i << " % " << j << " = " << i%j << "\n";
			if (i%j == 0) divisor++;
		}
		
		//約数の個数で判別。
		if (divisor == 2) {
			std::cout << i << "は素数です。\n";
		}else{
			//std::cout << i << "は素数ではありません。\n";
		}
	}
	return 0;
}

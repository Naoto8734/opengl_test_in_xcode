//
//  test_ass.hpp
//  practice_cpp
//
//  Created by Naoto on 2017/08/14.
//  Copyright © 2017年 NYamashita. All rights reserved.
//

#ifndef test_ass_hpp
#define test_ass_hpp

class myclass {
	int myprivate_a;
	
public:
	myclass();
	~myclass();
	
	int get_a();
	void set_a(int num);
};

#endif /* test_ass_hpp */

/*
时间：2019年4月3日20:07:02
目的：将所有常用到的头文件包含到同一个.h文件中，以后只需要引用即可！
难点：对于一个头文件的作用还是了解得不是很透彻。
1.iomanip:非常类似于C语言中的标准输出
	①dec 置基数为10 相当于"%d";hex 置基数为16 相当于"%X";oct 置基数为8 相当于"%o"
	②setw( n ) 设域宽为n个字符
		列2：	如 cout<<setw(5)<<255<<endl;
				结果是:(空格)(空格)255
	③setfill( 'c' ) 设填充字符为c
		列1：	cout<<setfill(‘@‘)<<setw(5)<<255<<endl;
				结果是:@@255
	④setbase(int n) : 将数字转换为 n 进制
		列3：	如 cout<<setbase(8)<<setw(5)<<255<<endl;
				结果是:(空格)(空格)377
	⑤setprecision( n ) 设显示有效数字为n位
		使用setprecision(n)可控制输出流显示浮点数的数字个数。
		C++默认的流输出数值有效位是6。
		与setiosflags(ios::fixed)合用，可以控制小数点右边的数字个数
		与setiosflags(ios::scientific)合用， 可以控制指数表示法的小数位数
*/




#pragma once
//C.h几乎包含各程序需要的头文件以及使用空间
#ifndef _C_H
#define _C_H
#include <iostream>		//cout、cin、std等
#include <fstream>		//fin等(对于文件进行操作)
#include <iomanip>		//setw()等:
#include <cmath>		//数学函数头文件
#include <vector>		//STL中的向量
#include <list>			//STL中的链表
#include <stack>		//STL中的栈
#include <queue>		//STL中的队列和优先队列
#include <string>		//字符串
#include <bitset>		//位集合
#include <algorithm>	//通用算法
#include <ctime>		//clock()等
#include <cstdarg>		//提供宏va_start、va_arg和va_end,用于存取变长参数表
#include <assert.h>		//assert宏
using namespace std;	//使用命名空间
#endif // !_C_H
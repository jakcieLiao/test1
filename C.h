/*
ʱ�䣺2019��4��3��20:07:02
Ŀ�ģ������г��õ���ͷ�ļ�������ͬһ��.h�ļ��У��Ժ�ֻ��Ҫ���ü��ɣ�
�ѵ㣺����һ��ͷ�ļ������û����˽�ò��Ǻ�͸����
1.iomanip:�ǳ�������C�����еı�׼���
	��dec �û���Ϊ10 �൱��"%d";hex �û���Ϊ16 �൱��"%X";oct �û���Ϊ8 �൱��"%o"
	��setw( n ) �����Ϊn���ַ�
		��2��	�� cout<<setw(5)<<255<<endl;
				�����:(�ո�)(�ո�)255
	��setfill( 'c' ) ������ַ�Ϊc
		��1��	cout<<setfill(��@��)<<setw(5)<<255<<endl;
				�����:@@255
	��setbase(int n) : ������ת��Ϊ n ����
		��3��	�� cout<<setbase(8)<<setw(5)<<255<<endl;
				�����:(�ո�)(�ո�)377
	��setprecision( n ) ����ʾ��Ч����Ϊnλ
		ʹ��setprecision(n)�ɿ����������ʾ�����������ָ�����
		C++Ĭ�ϵ��������ֵ��Чλ��6��
		��setiosflags(ios::fixed)���ã����Կ���С�����ұߵ����ָ���
		��setiosflags(ios::scientific)���ã� ���Կ���ָ����ʾ����С��λ��
*/




#pragma once
//C.h����������������Ҫ��ͷ�ļ��Լ�ʹ�ÿռ�
#ifndef _C_H
#define _C_H
#include <iostream>		//cout��cin��std��
#include <fstream>		//fin��(�����ļ����в���)
#include <iomanip>		//setw()��:
#include <cmath>		//��ѧ����ͷ�ļ�
#include <vector>		//STL�е�����
#include <list>			//STL�е�����
#include <stack>		//STL�е�ջ
#include <queue>		//STL�еĶ��к����ȶ���
#include <string>		//�ַ���
#include <bitset>		//λ����
#include <algorithm>	//ͨ���㷨
#include <ctime>		//clock()��
#include <cstdarg>		//�ṩ��va_start��va_arg��va_end,���ڴ�ȡ�䳤������
#include <assert.h>		//assert��
using namespace std;	//ʹ�������ռ�
#endif // !_C_H
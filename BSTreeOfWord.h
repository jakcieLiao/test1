#pragma once
/*
字符串里面的字符只有英文字母(大小写)，数字，英文的标点符号(,.?!-:"'以及空格字符)
*/

#pragma once
#include "C.h"
#include <malloc.h>

typedef struct BST
{
	char key[20];
	int count;
	struct BST *lchild, *rchild;
}BSN, *BSTRee1;

//void init_BST(BSTRee1 &Tree);					      //初始化
void insertBSTree(BSTRee1 &Tree, string str);	//将字符串str插入二叉排序树
bool serchBSTree(BSTRee1 Tree, string str);	  //查找二叉排序树中是否有关键字为str的元素
BSTRee1 ParentNode(BSTRee1 Tree, string str);	//返回关键字为str元素的父节点
bool isCharacter(char c);					            //判断是否为英文字母
void cToString(BSTRee1 &Tree, string str);		//将输入的字符串转换为一个一个小的字符串
void visit(BSN *pNode);
void preTraversalBSTR(BSTRee1 Tree);

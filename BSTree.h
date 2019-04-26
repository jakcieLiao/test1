#pragma once
#include "C.h"
#include <malloc.h>

typedef struct BSTree
{
	char key;
	int count;
	struct BSTree *lchild, *rchild;
}BSNode, *BSTRee;

//void init_BSTree(BSTRee &Tree);
void insertBSTree(BSTRee &Tree, char c);	//将字符c插入二叉排序树
bool serchBSTree(BSTRee Tree, char c);		//查找二叉排序树中是否有关键字为c的元素
BSTRee ParentNode(BSTRee Tree, char c);		//返回关键字为c元素的父节点
void visit(BSNode *Node);					//访问节点元素
void preTraversal(BSTRee Tree);				//先序遍历二叉排序树


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
void insertBSTree(BSTRee &Tree, char c);	//���ַ�c�������������
bool serchBSTree(BSTRee Tree, char c);		//���Ҷ������������Ƿ��йؼ���Ϊc��Ԫ��
BSTRee ParentNode(BSTRee Tree, char c);		//���عؼ���ΪcԪ�صĸ��ڵ�
void visit(BSNode *Node);					//���ʽڵ�Ԫ��
void preTraversal(BSTRee Tree);				//�����������������


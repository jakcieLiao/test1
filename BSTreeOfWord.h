#pragma once
/*
�ַ���������ַ�ֻ��Ӣ����ĸ(��Сд)�����֣�Ӣ�ĵı�����(,.?!-:"'�Լ��ո��ַ�)
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

void insertBSTree(BSTRee1 &Tree, string str);	//���ַ���str�������������
bool serchBSTree(BSTRee1 Tree, string str);		//���Ҷ������������Ƿ��йؼ���Ϊstr��Ԫ��
BSTRee1 ParentNode(BSTRee1 Tree, string str);	//���عؼ���ΪstrԪ�صĸ��ڵ�
bool isCharacter(char c);						//�ж��Ƿ�ΪӢ����ĸ
void cToString(BSTRee1 &Tree, string str);		//��������ַ���ת��Ϊһ��һ��С���ַ���
void visit(BSN *pNode);							//����ÿһ���ڵ㣬�����ڵ���Ϣ¼���ļ���
void preTraversalBSTR(BSTRee1 Tree);			//�����������������
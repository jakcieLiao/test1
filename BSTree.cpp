#include "BSTree.h"

//���عؼ���ΪcԪ�صĸ��ڵ�
BSTRee ParentNode(BSTRee Tree, char c)
{
	BSTRee parent;

	parent = Tree;
	while (Tree)
	{
		if (c < Tree->key)
		{
			parent = Tree;
			Tree = Tree->lchild;
		}
		else
		{
			parent = Tree;
			Tree = Tree->rchild;
		}
	}

	return parent;
}

//���ַ�c�������������
void insertBSTree(BSTRee &Tree, char c)
{
	BSTRee parent, TNode;	//parent����Ҫ������ַ��ĸ��ڵ㣬TNode����Ҫ�²���Ľڵ�

	TNode = (BSTRee)malloc(sizeof(struct BSTree));
	TNode->count = 1;
	TNode->key = c;
	TNode->lchild = NULL;
	TNode->rchild = NULL;
	//���TreeΪ��
	if (Tree == NULL)
	{
		Tree = TNode;
		return;
	}
	//���ַ�c���ڶ�����������ʱ,������parentֵ
	else if (!serchBSTree(Tree, c))
	{
		parent = ParentNode(Tree, c);
		if (c < parent->key)		//�ؼ�ֵ���丸�ڵ�С������Ϊ���ӽڵ�
			parent->lchild = TNode;
		else
			parent->rchild = TNode;
		return;
	}
	else			//���ַ�c�ڶ�����������ʱ,��countֵ��1
	{
		if (c == Tree->key)
			Tree->count++;
		else if (c < Tree->key)
			insertBSTree(Tree->lchild, c);
		else
			insertBSTree(Tree->rchild, c);
	}
	return;
}

//���Ҷ������������Ƿ��йؼ���Ϊc��Ԫ��
bool serchBSTree(BSTRee Tree, char c)
{
	while (Tree)
	{
		if (c == Tree->key)
			return true;
		else if (c < Tree->key)
			Tree = Tree->lchild;
		else
			Tree = Tree->rchild;
	}

	return false;
}

//���ʽڵ�Ԫ��
void visit(BSNode *Node)
{
	ofstream file("BSTree.txt", ios::app);
	if (Node && file.is_open())
		file << "[" << Node->key << ":" << Node->count << "]" << endl;
}


void preTraversal(BSTRee Tree)
{
	if (Tree)
	{
		visit(Tree);
		preTraversal(Tree->lchild);
		preTraversal(Tree->rchild);
	}
}

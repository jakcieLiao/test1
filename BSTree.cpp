#include "BSTree.h"

//返回关键字为c元素的父节点
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

//将字符c插入二叉排序树
void insertBSTree(BSTRee &Tree, char c)
{
	BSTRee parent, TNode;	//parent返回要插入的字符的父节点，TNode代表要新插入的节点

	TNode = (BSTRee)malloc(sizeof(struct BSTree));
	TNode->count = 1;
	TNode->key = c;
	TNode->lchild = NULL;
	TNode->rchild = NULL;
	//如果Tree为空
	if (Tree == NULL)
	{
		Tree = TNode;
		return;
	}
	//当字符c不在二叉排序树中时,返回其parent值
	else if (!serchBSTree(Tree, c))
	{
		parent = ParentNode(Tree, c);
		if (c < parent->key)		//关键值比其父节点小，插入为左孩子节点
			parent->lchild = TNode;
		else
			parent->rchild = TNode;
		return;
	}
	else			//当字符c在二叉排序树中时,其count值加1
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

//查找二叉排序树中是否有关键字为c的元素
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

//访问节点元素
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

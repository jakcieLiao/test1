#include "BSTreeOfWord.h"

//*******************************************************
//对字符串进行操作

//返回关键字为str元素的父节点
BSTRee1 ParentNode(BSTRee1 Tree, string str)
{
	BSTRee1 parent;

	parent = Tree;
	while (Tree)
	{
		if (str.compare(Tree->key) < 0)
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
void insertBSTree(BSTRee1 &Tree, string str)
{
	BSTRee1 parent, TNode;	//parent返回要插入的字符的父节点，TNode代表要新插入的节点

	TNode = (BSTRee1)malloc(sizeof(struct BST));
	//TNode->key = (char *)malloc(20 * sizeof(char));
	TNode->count = 1;
	strcpy_s(TNode->key, str.c_str());		//将string类型转换为字符串数组类型
	TNode->lchild = NULL;
	TNode->rchild = NULL;
	//如果Tree为空
	if (Tree == NULL)
	{
		Tree = TNode;
		return;
	}
	//当字符c不在二叉排序树中时,返回其parent值
	else if (!serchBSTree(Tree, str))
	{
		parent = ParentNode(Tree, str);
		if (str.compare(parent->key) < 0)		//关键值比其父节点小，插入为左孩子节点
			parent->lchild = TNode;
		else
			parent->rchild = TNode;
		return;
	}
	else			//当字符c在二叉排序树中时,其count值加1
	{
		if (str.compare(Tree->key) == 0)
			Tree->count++;
		else if (str.compare(Tree->key) < 0)
			insertBSTree(Tree->lchild, str);
		else
			insertBSTree(Tree->rchild, str);
	}
	return;
}

//查找二叉排序树中是否有关键字为c的元素
bool serchBSTree(BSTRee1 Tree, string str)
{
	while (Tree)
	{
		if (str.compare(Tree->key) == 0)
			return true;
		else if (str.compare(Tree->key) < 0)
			Tree = Tree->lchild;
		else
			Tree = Tree->rchild;
	}

	return false;
}

//判断是否为英文字母:英文的标点符号(, . ? !- : "'以及空格字符)
bool isCharacter(char c)
{
	if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122))
		return true;
	else
		return false;
}

//将输入的字符串转换为一个一个小的字符串
void cToString(BSTRee1 &Tree, string str)
{
	char buffer[1000], str1[20] = { ' ' };		//将输入的str暂存至buffer，str1存储单词

	strcpy_s(buffer, str.c_str());
	strcat_s(buffer, "#");						//在结束之前加上一个"#"
	for (int i = 0,k = 0; buffer[i]; i++)
	{
		if (isCharacter(buffer[i]))		//只对英文字母以及数字进行二叉排序树的存储
		{
			str1[k++] = buffer[i];
			continue;
		}
		str1[k] = 0;
		if(str1[0] != 0)
		{
			string string1(str1);		//在初始化时将字符串数组转换为string类型
			insertBSTree(Tree, string1);
			str1[0] = 0;
		}
		k = 0;
	}
}

void visit(BSN *pNode)
{
	ofstream file("wordBSTree.txt", ios::app);
	if (pNode && file.is_open())
		file << "[" << pNode->key << ":" << pNode->count << "]" << endl;
}

//先序遍历字符串
void preTraversalBSTR(BSTRee1 Tree)
{
	if (Tree)
	{
		visit(Tree);
		preTraversalBSTR(Tree->lchild);
		preTraversalBSTR(Tree->rchild);
	}
}


#include "BSTreeOfWord.h"

//*******************************************************
//���ַ������в���

//���عؼ���ΪstrԪ�صĸ��ڵ�
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

//���ַ�c�������������
void insertBSTree(BSTRee1 &Tree, string str)
{
	BSTRee1 parent, TNode;	//parent����Ҫ������ַ��ĸ��ڵ㣬TNode����Ҫ�²���Ľڵ�

	TNode = (BSTRee1)malloc(sizeof(struct BST));
	//TNode->key = (char *)malloc(20 * sizeof(char));
	TNode->count = 1;
	strcpy_s(TNode->key, str.c_str());		//��string����ת��Ϊ�ַ�����������
	TNode->lchild = NULL;
	TNode->rchild = NULL;
	//���TreeΪ��
	if (Tree == NULL)
	{
		Tree = TNode;
		return;
	}
	//���ַ�c���ڶ�����������ʱ,������parentֵ
	else if (!serchBSTree(Tree, str))
	{
		parent = ParentNode(Tree, str);
		if (str.compare(parent->key) < 0)		//�ؼ�ֵ���丸�ڵ�С������Ϊ���ӽڵ�
			parent->lchild = TNode;
		else
			parent->rchild = TNode;
		return;
	}
	else			//���ַ�c�ڶ�����������ʱ,��countֵ��1
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

//���Ҷ������������Ƿ��йؼ���Ϊc��Ԫ��
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

//�ж��Ƿ�ΪӢ����ĸ:Ӣ�ĵı�����(, . ? !- : "'�Լ��ո��ַ�)
bool isCharacter(char c)
{
	if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122))
		return true;
	else
		return false;
}

//��������ַ���ת��Ϊһ��һ��С���ַ���
void cToString(BSTRee1 &Tree, string str)
{
	char buffer[1000], str1[20] = { ' ' };		//�������str�ݴ���buffer��str1�洢����

	strcpy_s(buffer, str.c_str());
	strcat_s(buffer, "#");						//�ڽ���֮ǰ����һ��"#"
	for (int i = 0,k = 0; buffer[i]; i++)
	{
		if (isCharacter(buffer[i]))		//ֻ��Ӣ����ĸ�Լ����ֽ��ж����������Ĵ洢
		{
			str1[k++] = buffer[i];
			continue;
		}
		str1[k] = 0;
		if(str1[0] != 0)
		{
			string string1(str1);		//�ڳ�ʼ��ʱ���ַ�������ת��Ϊstring����
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

//��������ַ���
void preTraversalBSTR(BSTRee1 Tree)
{
	if (Tree)
	{
		visit(Tree);
		preTraversalBSTR(Tree->lchild);
		preTraversalBSTR(Tree->rchild);
	}
}


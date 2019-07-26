#ifndef  _BTREE_H_
#define  _BTREE_H_

#include<stdio.h>
#include<Windows.h>

#define  ENDTAG  '#'
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode *_left;
	struct BinaryTreeNode *_right;
}BTNode;

//����һ����
BTNode *BinaryTreeCreate(BTDataType *a);

//�ݹ����
void BinaryTreePrevOrder(BTNode *root);//ǰ�����
void BinaryTreeInOrder(BTNode *root);//�������
void BinaryTreePostOrder(BTNode *root);//�������

void BinaryTreeLevelOrder(BTNode *root);//�������

//�ǵݹ����
void BinaryTreePrevOrderNonR(BTNode *root);//ǰ�����
void BinaryTreeInOrderNonR(BTNode *root);//�������
void BinaryTreePostOrderNonR(BTNode *root);//�������

//�����ַ



#endif/*_BTREE_H_*/
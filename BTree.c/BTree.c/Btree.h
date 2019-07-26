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

//创建一个树
BTNode *BinaryTreeCreate(BTDataType *a);

//递归遍历
void BinaryTreePrevOrder(BTNode *root);//前序遍历
void BinaryTreeInOrder(BTNode *root);//中序遍历
void BinaryTreePostOrder(BTNode *root);//后序遍历

void BinaryTreeLevelOrder(BTNode *root);//层序遍历

//非递归遍历
void BinaryTreePrevOrderNonR(BTNode *root);//前序遍历
void BinaryTreeInOrderNonR(BTNode *root);//中序遍历
void BinaryTreePostOrderNonR(BTNode *root);//后序遍历

//存结点地址



#endif/*_BTREE_H_*/
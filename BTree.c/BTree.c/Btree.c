#include "Btree.h"
#include "queue.h"

BTNode *BinaryTreeCreate(BTDataType *a)
{
	BTNode *cur;
	static int i = 0;

	if (a[i] == ENDTAG)
	{
		i++;
		return NULL;
	}
	cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = a[i];
	i++;
	cur->_left = BinaryTreeCreate(a);
	cur->_right = BinaryTreeCreate(a);

	return cur;
}

void BinaryTreePrevOrder(BTNode *root)
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
	
}
void BinaryTreeInOrder(BTNode *root)
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	
}

void BinaryTreePostOrder(BTNode *root)
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}

void BinaryTreeLevelOrder(BTNode *root)//≤„–Ú±È¿˙<π„∂»À—À˜>
{
	Queue pq;
	BTNode *tmp;
	QueueInit(&pq);

	QueuePush(&pq,root);

	while (QueueEmpty(&pq))
	{
		tmp = QueueFront(&pq);
		printf("%c", tmp->_data);
		if (tmp->_left)
		{
			QueuePush(&pq, tmp->_left);
		}
		if (tmp->_right)
		{
			QueuePush(&pq, tmp->_right);
		}
		QueuePop(&pq);
	}
	QueueDestory(&pq);
}

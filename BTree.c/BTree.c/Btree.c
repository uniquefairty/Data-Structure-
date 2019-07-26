#include "Btree.h"
#include "queue.h"
#include "stack.h"

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

void BinaryTreeLevelOrder(BTNode *root)//�������<�������>
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


void BinaryTreePrevOrderNonR(BTNode *root)//��ߴ�ӡ���ұ�ѹջ
{
	Stack st;
	BTNode *cur = root;
	
	StackInit(&st,20);

	while (cur || StackEmpty(&st))
	{
		putchar(cur->_data);

		if (cur->_right)
		{
			StackPush(&st, cur->_right);
		}

		if (cur->_left)
		{
			cur = cur->_left;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}
void BinaryTreeInOrderNonR(BTNode *root)//�������//  һֱ��ѹ��ջʱѹ��
{
	Stack st;
	BTNode *cur = root;
	
	StackInit(&st, 20);

	while (cur || StackEmpty(&st))
	{
		for (; cur; cur = cur->_left)
		{
			StackPush(&st, cur);
		}

		//if (StackEmpty(&st))
		//{
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
			cur = cur->_right;
		//}
	}
	StackDestory(&st);
}
//void BinaryTreeInOrderNonR(BTNode *root)//�������//  һֱ��ѹ��ջʱѹ��
//{
//	Stack st;
//	BTNode *cur = root;
//
//	StackInit(&st, 20);
//	while (1)
//	{
//		for (; cur; cur = cur->_left)//��Ŀǰ�ĸ��Լ������е�����ѹջ��ֱ���Ҳ�������
//		{
//			StackPush(&st, cur);
//		}
//
//		while (1)
//		{
//			cur = StackTop(&st);
//			putchar(cur->_data);
//			StackPop(&st);
//			if (cur->_right)
//			{
//				cur = cur->_right;
//				break;
//			}
//			if (!StackEmpty(&st))
//			{
//				StackDestory(&st);
//				return;
//			}
//		}
//	}
//}
void BinaryTreePostOrderNonR(BTNode *root)//�������
{
	BTNode *cur = root;
	Stack st;
	int tag[32] = { 0 };
	StackInit(&st, 20);

	while (cur || StackEmpty(&st))
	{
		for (; cur; cur = cur->_left)
		{
			StackPush(&st, cur);
			tag[st.top] = 0;
		}

		while (StackEmpty(&st) && tag[st.top] == 1)
		{
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
			cur = NULL;
		}

		if (StackEmpty(&st))
		{
			tag[st.top] = 1;
			cur = StackTop(&st)->_right;
		}
	}
	StackDestory(&st);
}
//size����
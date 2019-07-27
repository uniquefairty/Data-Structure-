#include "Btree.h"
#include "queue.h"
#include "stack.h"

//����һ����
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

//�ݹ����
void BinaryTreePrevOrder(BTNode *root)//ǰ�����
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}


void BinaryTreeInOrder(BTNode *root)//�������
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	
}

void BinaryTreePostOrder(BTNode *root)//�������
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


void BinaryTreePrevOrderNonR(BTNode *root)//ǰ���������ߴ�ӡ���ұ�ѹջ��
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

	while (cur || StackEmpty(&st))//��curΪ����ջΪ��ʱ��ѭ���������������������
	{
		for (; cur; cur = cur->_left)
			//1.��Ŀǰ�ĸ��������е�����ѹջ��ֱ���Ҳ�������Ϊֹ
			//2.��Ŀǰ���Һ�����Ϊ��������������������ѹջ
		{
			StackPush(&st, cur);
		}

		//if (StackEmpty(&st))
		//{
			cur = StackTop(&st);
			//1.���ӱ�����Ϻ󣬵�һ��û�����ӵĽڵ��������ĵ�һ�����
			//2.����Һ���Ϊ��<��ִ�����������������>����ʱջ�ｫ������һ��Ҫ���ʵĽڵ�
			//  ������Һ��ӣ���ô��ʱջ�ｫ�������Ǹ��Һ���Ϊ���������е�һ��û�����ӵĽڵ�
			putchar(cur->_data);
			//1.����û�����ӣ����Դ�ӡ��
			StackPop(&st);
			cur = cur->_right;
			//1.�������͸����������󣬱�������������
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
	int tag[32] = { 0 };//���ӱ�����ǩ
	StackInit(&st, 20);

	while (cur || StackEmpty(&st))//��curΪ��ʱ��ѭ���������������������
	{
		for (; cur; cur = cur->_left)//1.�������򣬽�������ջ2.curΪ��ʱ��������һ���ڵ���Һ���Ϊ�գ�ֻ������������ſ��ܽ��������ѭ��
		{
			StackPush(&st, cur);//push�����ᵼ��top+1
			tag[st.top] = 0;
		}

		//ֻҪ�����forִ�й�һ��ѭ�����Һ��Ӳ�Ϊ�գ������whil�ĺ�벿������������������
		while (StackEmpty(&st) && tag[st.top] == 1)//���ӻ�û�������ʱ�����ܽ����ӡ
			//���ԣ�����ȷ����ֻ�������������������ʱ���Ż�������while
		{
			cur = StackTop(&st);
			putchar(cur->_data);//��ӡ��
			StackPop(&st);//pop�����ᵼ��top-1
			cur = NULL;//Ϊ��ѭ����������
		}//���ڵ��ӡ

		if (StackEmpty(&st))
		{
			tag[st.top] = 1;//��������֤��������������ϣ���������ǩ1
			cur = StackTop(&st)->_right;//������������������
		}
	}
	StackDestory(&st);
}
//size����


// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue pq;
	BTNode *tmp;
	int leafflag = 0;
	QueueInit(&pq);

	QueuePush(&pq, root);

	while (QueueEmpty(&pq))
	{
		tmp = QueueFront(&pq);
		printf("%c", tmp->_data);
		QueuePop(&pq);//����ϴ�ѭ��ִ��continue��˵����Ҷ�ӽڵ㣬�����ϴ�ѭ�����������з���������Ԫ�����ܳ����У���һֱ����continue������
		if (leafflag)
		{
			if (tmp->_left || tmp->_right)
			{
				return 0;
			}
			continue;
		}
		
		if (tmp->_right &&tmp->_left)
		{
			QueuePush(&pq, tmp->_left);
			QueuePush(&pq, tmp->_right);
		}
		else if (tmp->_right&&!tmp->_left)
		{
			return 0;
		}
		else
		{
			leafflag = 1;
			if (tmp->_left)
			{
				QueuePush(&pq, tmp->_left);
			}
		}

	}
	QueueDestory(&pq);
	return 1;
}

void BinaryTreeDestory(BTNode* root)
{
	BTNode *left, *right;
	if (root)
	{
		left = root->_left;
		right = root->_right;
		free(root);
		BinaryTreeDestory(left);
		BinaryTreeDestory(right);
	}
}
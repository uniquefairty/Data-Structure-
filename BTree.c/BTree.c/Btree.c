#include "Btree.h"
#include "queue.h"
#include "stack.h"

//创建一棵树
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

//递归遍历
void BinaryTreePrevOrder(BTNode *root)//前序遍历
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}


void BinaryTreeInOrder(BTNode *root)//中序遍历
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	
}

void BinaryTreePostOrder(BTNode *root)//后序遍历
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}

void BinaryTreeLevelOrder(BTNode *root)//层序遍历<广度搜索>
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


void BinaryTreePrevOrderNonR(BTNode *root)//前序遍历（左边打印，右边压栈）
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
void BinaryTreeInOrderNonR(BTNode *root)//中序遍历//  一直左压出栈时压右
{
	Stack st;
	BTNode *cur = root;
	
	StackInit(&st, 20);

	while (cur || StackEmpty(&st))//当cur为空且栈为空时，循环跳出，代表树遍历完毕
	{
		for (; cur; cur = cur->_left)
			//1.把目前的根及其所有的左孩子压栈，直到找不到左孩子为止
			//2.把目前的右孩子作为根，继续将他的左孩子们压栈
		{
			StackPush(&st, cur);
		}

		//if (StackEmpty(&st))
		//{
			cur = StackTop(&st);
			//1.左孩子遍历完毕后，第一个没有左孩子的节点就是中序的第一个输出
			//2.如果右孩子为空<不执行上面的左子树遍历>，此时栈里将会是下一个要访问的节点
			//  如果有右孩子，那么此时栈里将会是以那个右孩子为根的子树中第一个没有左孩子的节点
			putchar(cur->_data);
			//1.由于没有左孩子，所以打印根
			StackPop(&st);
			cur = cur->_right;
			//1.左子树和根遍历结束后，遍历它的右子树
		//}
	}
	StackDestory(&st);
}
//void BinaryTreeInOrderNonR(BTNode *root)//中序遍历//  一直左压出栈时压右
//{
//	Stack st;
//	BTNode *cur = root;
//
//	StackInit(&st, 20);
//	while (1)
//	{
//		for (; cur; cur = cur->_left)//把目前的根以及根所有的左孩子压栈，直到找不到左孩子
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
void BinaryTreePostOrderNonR(BTNode *root)//后序遍历
{
	BTNode *cur = root;
	Stack st;
	int tag[32] = { 0 };//左孩子遍历标签
	StackInit(&st, 20);

	while (cur || StackEmpty(&st))//当cur为空时，循坏跳出，代表树遍历完毕
	{
		for (; cur; cur = cur->_left)//1.类似中序，将左孩子入栈2.cur为空时，代表上一个节点的右孩子为空，只有这种情况，才可能进入下面的循环
		{
			StackPush(&st, cur);//push操作会导致top+1
			tag[st.top] = 0;
		}

		//只要上面的for执行过一次循环（右孩子不为空），这个whil的后半部分条件都不可能满足
		while (StackEmpty(&st) && tag[st.top] == 1)//左孩子还没遍历完成时，不能进入打印
			//所以，这里确保了只有左右子树都遍历完成时，才会进入这个while
		{
			cur = StackTop(&st);
			putchar(cur->_data);//打印根
			StackPop(&st);//pop操作会导致top-1
			cur = NULL;//为了循环正常跳出
		}//父节点打印

		if (StackEmpty(&st))
		{
			tag[st.top] = 1;//进入这里证明左子树遍历完毕，左子树标签1
			cur = StackTop(&st)->_right;//进入右子树继续遍历
		}
	}
	StackDestory(&st);
}
//size层数


// 判断二叉树是否是完全二叉树
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
		QueuePop(&pq);//如果上次循环执行continue，说明是叶子节点，结束上次循环（若出队列放在最后，这个元素则不能出队列，则一直进行continue操作）
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
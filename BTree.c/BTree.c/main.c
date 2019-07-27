#include "Btree.h"
int main()
{

	BTNode *testTree = BinaryTreeCreate("ABD##E#H##CF##G##");
	//BinaryTreePrevOrder(testTree);
	//putchar('\n');
	/*BinaryTreeInOrder(testTree);
	putchar('\n');
	BinaryTreePostOrder(testTree);
	putchar('\n');
	BinaryTreeLevelOrder(testTree);
	putchar('\n');*/
	//BinaryTreePrevOrderNonR(testTree);
	//putchar('\n');
	//BinaryTreePostOrderNonR(testTree);
	printf("%d",BinaryTreeComplete(testTree));
	system("pause");
	return 0;
}
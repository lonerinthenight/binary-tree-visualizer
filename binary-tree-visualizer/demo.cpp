#include "binarytree.hpp"
#include "linkedlist.hpp"

int main()
{
	// build a binary tree like this:
	//        5
	//       / \
	//      2   7
	//     / \   \
	//    1   4   8
	TreeNode *root = makeTree({ 5,2,7,1,4,null,8 });
	// visualize the binary tree using GraphViz.
	showTree(root);
	// delete the binary tree.
	delTree(root);

	// Build a linked list like this:
	// 5 -> 2 -> 0 -> 1 -> 3 -> 1 -> 4 -> NULL
	ListNode *head = makeList({ 5,2,0,1,3,1,4 });
	// visualize the linked list using GraphViz.
	showList(head);
	// delete the linked list.
	delList(head);
	return 0;
}
#include "binarytree.hpp"
#include "linkedlist.hpp"
#include <iostream>
#include <exception>

int main()
{
	// build a binary tree like this:
	//        5
	//       / \
	//      2   7
	//     / \   \
	//    1   4   8
	TreeNode *root = makeTree({ 5,2,7,1,4,null,8 });
	try
	{
		// visualize the binary tree using GraphViz.
		showTree(root);
		// delete the binary tree.
		delTree(root);
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	// Build a linked list like this:
	// 5 -> 2 -> 0 -> 1 -> 3 -> 1 -> 4 -> NULL
	ListNode *head = makeList({ 5,2,0,1,3,1,4 });
	try
	{
		// visualize the linked list using GraphViz.
		showList(head);
		// delete the linked list.
		delList(head);
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}

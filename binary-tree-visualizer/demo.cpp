#include "binarytree.hpp"
#include "linkedlist.hpp"
#include <iostream>
#include <exception>

int main()
{
	// build a binary tree like this:
	//        5                       5
	//       / \                   /     \
	//      2   7                 2       7
	//     / \   \     -->      /   \    / \
	//    1   4   8    -->     1     4  n   8
	//     \     /            / \   / \    /
	//      0   9            n   0 n   n  9
	// Note: `n` represents null (empty node).
	TreeNode *root = makeTree({ 5,2,7,1,4,null,8,null,0,null,null,9 });
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

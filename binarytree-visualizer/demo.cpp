#include "binarytree.hpp"

int main()
{
	// build a binary search tree.
	TreeNode *root = makeTree({ 5,2,7,1,4,null,8 });
	// visualize the binary tree using GraphViz.
	showTree(root);
	// Delete the binary tree and the list.
	delTree(root);
	return 0;
}
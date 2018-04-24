#include "binarytree.hpp"

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
	return 0;
}

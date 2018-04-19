#pragma once
#include <stdint.h>
#include <initializer_list>

constexpr int null = INT32_MIN;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

extern TreeNode * makeTree(const std::initializer_list<int> && init);
extern void delTree(TreeNode * root);
extern void showTree(const TreeNode *root);

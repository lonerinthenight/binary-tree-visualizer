#pragma once
#include <stdint.h>
#include <vector>

constexpr int null = INT32_MIN;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

extern TreeNode * makeTree(const std::vector<int> & values, int i = 0);
extern TreeNode * makeTree(const std::vector<int> && values);
extern void delTree(TreeNode * root);
extern void showTree(const TreeNode *root);

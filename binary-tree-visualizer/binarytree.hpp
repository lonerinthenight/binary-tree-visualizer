/**
 * @brief TreeNode definition and related functions
 * 
 * @file binarytree.hpp
 * @author Haotian Wang
 * @date 2018-07-07
 */
#pragma once
#include <stdint.h>
#include <vector>
#include <limits>

/// In function `makeTree`, `null` is used to represent empty node.
constexpr int null = INT32_MIN;

/// Definition of TreeNode, compatible with LeetCode.
struct TreeNode
{
	int val;            ///< Value of the tree node
	TreeNode *left;     ///< Pointer to the left child
	TreeNode *right;    ///< Pointer to the right child

	/**
	 * @brief Construct a new tree node object
	 * 
	 * @param x Value of the tree node
	 */
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * @brief Build a binary tree from a vector
 * 
 * @param values  The level order traversal sequence of a binary tree.
 *                You can use `null` to represent empty node.
 *                For example, the following tree
 * ```
 *                       5
 *                      / \
 *                     2   7
 *                    / \   \
 *                   1   4   8
 * ```
 *                can be represented by { 5, 2, 7, 1, 4, null, 8 }
 * @param i       (Optional) The start index in the array `values`.
 * @return        The root of the binary tree.
 */
extern TreeNode * makeTree(const std::vector<int> & values, int i = 0) noexcept;

/**
 * @brief Delete a binary tree
 * 
 * @param root The tree to be deleted
 *
 * @note  We recommend you to set `root` to `nullptr` after deleting it.
 */
extern void delTree(TreeNode * root);

/**
 * @brief Visualize a binary tree using GraphViz
 * 
 * @param root The tree to be visualized
 */
extern void showTree(const TreeNode *root);

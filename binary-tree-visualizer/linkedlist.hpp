/**
 * @brief ListNode definition and related functions
 * 
 * @file linkedlist.hpp
 * @author Haotian Wang
 * @date 2018-07-07
 */
#pragma once
#include <initializer_list>

/// Definition of ListNode, compatible with LeetCode.
struct ListNode
{
	int val;           ///< Value of the list node
	ListNode *next;    ///< Pointer to the next node

	/**
	 * @brief Construct a new list node object
	 * 
	 * @param x Value of the list node
	 */
	ListNode(int x) noexcept : val(x), next(nullptr) {}
};

/**
 * @brief Build a linked list from an iterable object
 * 
 * @tparam Container  An iterable object, like `std::vector`, `std::list`, etc
 * @param  values     Values of the list
 * @return            The head of the list
 */
template <typename Container>
ListNode *makeList(const Container & values) noexcept
{
	ListNode dummy(0), *p = &dummy;
	for (int value : values)
	{
		p->next = new ListNode(value);
		p = p->next;
	}
	return dummy.next;
}

/**
 * @brief Build a linked list from an initializer list
 *
 * @details This function is based on initializer list (C++11).
 *          It can be called like this:  
 *          ListNode *head = makeList({5, 2, 0, 1, 3, 1, 4});
 * @param values  An initializer list
 * @return        The head of the list
 */
inline ListNode *makeList(std::initializer_list<int> && values) noexcept
{
	return makeList(values);
}

/**
 * @brief Delete a linked list
 * 
 * @param head The list to be deleted
 *
 * @note We recommend you to set `p` to `nullptr` after deleting it.
 */
extern void delList(ListNode *head) noexcept;

/**
 * @brief Visualize a binary tree using GraphViz
 * 
 * @param head The list to be visualized
 */
extern void showList(const ListNode *head);

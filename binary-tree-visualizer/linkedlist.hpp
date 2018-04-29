#pragma once
#include <initializer_list>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

template <typename Container>
ListNode * makeList(const Container & values)
{
	ListNode dummy(0), *p = &dummy;
	for (int value : values)
	{
		p->next = new ListNode(value);
		p = p->next;
	}
	return dummy.next;
}

static ListNode * makeList(std::initializer_list<int> && values)
{
	return makeList(values);
}

extern void delList(ListNode * p);
extern void showList(const ListNode *head);

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdexcept>
#include "linkedlist.hpp"

using namespace std;

void delList(ListNode * p)
{
	while (p)
	{
		ListNode * q = p;
		p = p->next;
		delete q;
	}
}


void showList(const ListNode *head)
{
	if (head == nullptr)
		throw runtime_error("The list node is null!");

	FILE * const fout = fopen("list.dot", "w");
	fprintf(fout, "digraph {\n");
	fprintf(fout, "    graph[ordering=\"out\", rankdir=LR];\n");

	int length = 0;	// 单链表的长度
	for (const ListNode *p = head; p != nullptr; p = p->next)
		fprintf(fout, "    Node%d[shape=\"circle\", label=\"%d\"];\n", length++, p->val);
	for (int i = 1; i < length; i++)
		fprintf(fout, "    Node%d -> Node%d\n", i - 1, i);

	fprintf(fout, "}\n");
	fclose(fout);

	// 调用GraphViz
	system("dot list.dot | neato -n -Tpng -o list.png");

	// 显示图片
#ifdef _WIN32
	system("list.png");
#endif
}

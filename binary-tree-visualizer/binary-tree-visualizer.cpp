#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stdexcept>
#include <unordered_map>
#include "binarytree.hpp"
#ifdef _MSC_VER
#include <io.h>
#define access _access
#else
#include <unistd.h>
#endif

using namespace std;

const char *gvprContent = R"(// from Emden Gansner
// https://mailman.research.att.com/pipermail/graphviz-interest/2010q2/007101.html
// requires GraphViz 2.28.0 (fails with 2.26.3 at least)
BEGIN {
  double tw[node_t];    // width of tree rooted at node
  double nw[node_t];    // width of node
  double xoff[node_t];  // x offset of root from left side of its tree
  double sp = 36;       // extra space between left and right subtrees
  double wd, w, w1, w2; 
  double x, y, z;
  edge_t e1, e2;
  node_t n;
}
BEG_G {
  $.bb = "";
  $tvtype=TV_postfwd;   // visit root after all children visited
}
N {
  sscanf ($.width, "%f", &w);
  w *= 72;  // convert inches to points
  nw[$] = w;
  if ($.outdegree == 0) {
    tw[$] = w;
    xoff[$] = w/2.0;
  }
  else if ($.outdegree == 1) {
    e1 = fstout($);
    w1 = tw[e1.head];    
    tw[$] = w1 + (sp+w)/2.0;
    if (e1.side == "left")
      xoff[$] = tw[$] - w/2.0;
    else
      xoff[$] = w/2.0;
  }
  else {
    e1 = fstout($);
    w1 = tw[e1.head];    
    e2 = nxtout(e1);
    w2 = tw[e2.head];    
    wd = w1 + w2 + sp;
    if (w > wd)
      wd = w;
    tw[$] = wd;
    xoff[$] = w1 + sp/2.0;
  }
}
BEG_G {
  $tvtype=TV_fwd;   // visit root first, then children
}
N {
  if ($.indegree == 0) {
    sscanf ($.pos, "%f,%f", &x, &y);
    $.pos = sprintf("0,%f", y);
  }
  if ($.outdegree == 0) return;
  sscanf ($.pos, "%f,%f", &x, &y);
  wd = tw[$];
  e1 = fstout($);
  n = e1.head;
  sscanf (n.pos, "%f,%f", &z, &y);
  if ($.outdegree == 1) {
    if (e1.side == "left")
      n.pos = sprintf("%f,%f",  x - tw[n] - sp/2.0 + xoff[n], y);
    else
      n.pos = sprintf("%f,%f", x + sp/2.0 + xoff[n], y);
  }
  else {
    n.pos = sprintf("%f,%f", x - tw[n] - sp/2.0 + xoff[n], y);
    e2 = nxtout(e1);
    n = e2.head;
    sscanf (n.pos, "%f,%f", &z, &y);
    n.pos = sprintf("%f,%f", x + sp/2.0 + xoff[n], y);
  }
})";


TreeNode * makeTree(const vector<int> & values, int i)
{
	if (i >= values.size() || values[i] == null)
		return nullptr;
	TreeNode * root = new TreeNode(values[i]);
	root->left = makeTree(values, i * 2 + 1);
	root->right = makeTree(values, i * 2 + 2);
	return root;
}


TreeNode * makeTree(const vector<int> && values)
{
	return makeTree(values, 0);
}


void delTree(TreeNode * root)
{
	if (!root)
		return;
	delTree(root->left);
	delTree(root->right);
	delete root;
}


void showTree(const TreeNode *root)
{
	if (root == nullptr)
		throw runtime_error("The tree node is null!");

	// 判断是否存在binarytree.gvpr，若不存在则创建一个
	if (access("binarytree.gvpr", 0))
	{
		FILE * const fout = fopen("binarytree.gvpr", "wb");
		fwrite(gvprContent, sizeof(char), strlen(gvprContent), fout);
		fclose(fout);
	}

	FILE * const fout = fopen("tree.dot", "w");

	fprintf(fout, "graph {\n");
	fprintf(fout, "    graph[ordering=\"out\"];\n");

	// 对二叉树进行层次遍历，获取每个节点对应的编号
	unordered_map<const TreeNode *, int> hash;
	queue<const TreeNode *> q;
	q.push(root);
	for (int idx = 0, nullidx = 0; !q.empty(); )
	{
		const TreeNode *p = q.front();
		q.pop();
		if (p == nullptr)
			fprintf(fout, "    NULL%d[style=\"invis\"];\n", nullidx++);
		else
		{
			hash[p] = idx;
			fprintf(fout, "    Node%d[shape=\"circle\", label=\"%d\"];\n", idx++, p->val);
			if (p->left || p->right)	// 如果是叶节点，则不需要将两个空节点放入队列
			{
				q.push(p->left);
				q.push(p->right);
			}
		}
	}

	// 再次对二叉树进行层次遍历，连接每个节点
	q.push(root);
	for (int nullidx = 0; !q.empty(); )
	{
		const TreeNode *p = q.front();
		q.pop();
		if (!p->left && !p->right)
			continue;	// 叶节点，没有子节点
		if (p->left)
		{
			fprintf(fout, "    Node%d -- Node%d;\n", hash[p], hash[p->left]);
			q.push(p->left);
		}
		else
			fprintf(fout, "    Node%d -- NULL%d[style=\"invis\"];\n", hash[p], nullidx++);
		if (p->right)
		{
			fprintf(fout, "    Node%d -- Node%d;\n", hash[p], hash[p->right]);
			q.push(p->right);
		}
		else
			fprintf(fout, "    Node%d -- NULL%d[style=\"invis\"];\n", hash[p], nullidx++);
	}

	fprintf(fout, "}\n");
	fclose(fout);

	// 调用GraphViz
	system("dot tree.dot | gvpr -c -f binarytree.gvpr | neato -n -Tpng -o tree.png");

	// 显示图片
#ifdef _WIN32
	system("tree.png");
#endif
}

#ifndef TREE_H
#define TREE_H

typedef struct node *tree;

struct node
{
	int val;
	tree fg, fd;
};

void printTree(tree a);
tree createNode(int v, tree fg, tree fd);
int research(int v, tree a);
tree insertNode(int v, tree a);
tree treeGeneration(int n);
tree deleteNode(int v,tree a);
#endif

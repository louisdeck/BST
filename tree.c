#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

#define TRUE 1
#define FALSE 0

void printTree(tree a)
{
	if(a != NULL)
	{
		printf("(%d,", a->val);
		printTree(a->fg);
		printf(",");
		printTree(a->fd);
		printf(")");
	}
	else printf("*");
}


tree createNode(int v, tree fg, tree fd)
{
	tree a;
	a = malloc(sizeof(struct node));

	assert(a != NULL);
	a->val = v;
	a->fg = fg;
	a->fd = fd;

	return a;
}


int research(int v, tree a)
{
	if(a == NULL)
		return FALSE;

	if(a->val == v)
		return TRUE;

	if(v < a->val)
		return research(v,a->fg);
	
	else return research(v,a->fd);
}


tree insertNode(int v, tree a)
{
	if(a == NULL)
		return createNode(v, NULL, NULL);

	if(v < a->val)
		a->fg = insertNode(v, a->fg);

	else if(v > a->val)
		a->fd = insertNode(v, a->fd);

	return a;
}


tree deleteNode(int v, tree a)
{
	tree p = a, prec = NULL;

	while((p!=NULL) && (p->val != v))
	{
		prec = p;

		if(v < p->val)
			p = p->fg;

		else if (v > p->val)
			p = p->fd;
	}

	if(p == NULL)
		return a;

	if(p->fg == NULL || p->fd == NULL) //node has 0 or 1 son
	{
		tree theSon = (p->fg != NULL)?p->fg:p->fd;

		if(prec != NULL)
		{
			if(p == prec->fg)
				prec->fg = theSon;

			else prec->fd = theSon;
		}
		else a = theSon;

		free(p);
	}

	else //node has 2 sons
	{

		tree q = p->fg, prec2 = p;

		while(q->fd != NULL)
		{	
			prec2 = q;
			q = q->fd;
		}

		p->val = q->val;

		if(prec2 != p)
			prec2->fd = q->fg;

		else p->fg=q->fg;

		free(q);
	}
	return a;
} 


tree treeGeneration(int n)
{
	tree a = NULL;

	printf("Number of nodes?\n");
	scanf("%d",&n);

	int *t;
	t = malloc(sizeof(int) * n);
	assert(t != NULL);

	printf("Input some values\n");

	for(int i=0; i<n; i++)
		scanf("%d", &t[i]); 

	for(int j=0; j<n; j++)
	{
		if(research(t[j],a) == FALSE)
			a = insertNode(t[j], a); 
	}
	free(t);

	return a;
}


void main()
{
	int n,delete, delete2, delete3;

	tree a = treeGeneration(n);
	printTree(a);

	printf("\n");
	printf("which value do you want to delete?\n");
	scanf("%d", &delete);
	a = deleteNode(delete,a);
	printTree(a);

	printf("\n");
	printf("which value do you want to delete?\n");
	scanf("%d", &delete2);
	a = deleteNode(delete2,a);
	printTree(a);

	printf("\n");
	printf("which value do you want to delete?\n");
	scanf("%d", &delete3);
	a = deleteNode(delete3,a);
	printTree(a);
}




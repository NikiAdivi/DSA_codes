#include<stdio.h>

typedef struct tree{
	int data;
	struct tree lc;
	struct tree rc;
	struct tree parent;
}Tree;

//Traversal

void inorder(Tree node)
{
	if(node!=NULL)
	{
	inorder(node->lc);
	printf("%d",node->data);
	inorder(node->rc);
	}
}

void create_tree(Tree node)


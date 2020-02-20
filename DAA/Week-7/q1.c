#include <stdio.h>
#include <stdlib.h>
#include "freefunc.h"
void findBalanceFactor(nodeptr root)
{
	if(!root) return;
	root->bf=height(root->lchild)-height(root->rchild);
	findBalanceFactor(root->lchild);
	findBalanceFactor(root->rchild);
	return;
}
void main()
{
	int x;
	nodeptr root=NULL;

	printf("Enter element for BST\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		root=createbst(root,x);
		printf("Enter element for BST\n");
		scanf("%d",&x);
	}	
	findBalanceFactor(root);
	preorderPrintBF(root);//BF=balance factor
}
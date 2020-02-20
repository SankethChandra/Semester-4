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
	printf("Enter root\n");
	scanf("%d",&x);
	nodeptr root=createbt(x);
	findBalanceFactor(root);
	preorderPrintBF(root);//BF=balance factor
	return;
}
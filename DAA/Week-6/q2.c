//with count done.
#include <stdio.h>
#include <stdlib.h>
#include "freefunc.h"
int count;
int getNum(nodeptr t)
{
	count++;
if(t == NULL)
    return 0;
else
    return 1 + getNum(t->lchild) + getNum(t->rchild);
}
void main()
{
	int data;
printf("Enter data for root of binary tree\n");
scanf("%d",&data);
nodeptr root=createbt(data);
count=0;
printf("The Number of Nodes of the Binary Tree is : %d\n ", getNum(root));
printf("count is %d\n",count );
}
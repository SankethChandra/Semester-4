#include<stdio.h>
#include<stdlib.h>
#include"freefunc.h"
int max(int a,int b)
{
    return (a>b)?a:b;
}
int height(nodeptr root)
{
    if(!root)
        return 0;
    return (max(height(root->lchild),height(root->rchild))+1);
}
int diameter(nodeptr root)
{
    if(!root)
        return 0;
    int lh=height(root->lchild);
    int rh=height(root->rchild);
    int ld=diameter(root->lchild);
    int rd=diameter(root->rchild);
    return max(lh+rh+1,max(ld,rd));
}

void main()
{
    int x;
    printf("Enter root value\n");
    scanf("%d",&x);
    nodeptr root=createbt(x);
    //inorder(root);
    printf("Diameter : %d",diameter(root));
    return;
}
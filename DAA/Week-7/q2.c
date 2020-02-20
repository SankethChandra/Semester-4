#include<stdio.h>
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

nodeptr rightRotate(nodeptr y) 
{ 
    nodeptr x = y->lchild; 
    nodeptr T2 = x->rchild; 
  
    // Perform rotation 
    x->rchild = y; 
    y->lchild = T2; 
  
    // Update heights 
    findBalanceFactor(x);
    findBalanceFactor(y);
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
nodeptr leftRotate(nodeptr x) 
{ 
    nodeptr y = x->rchild; 
    nodeptr T2 = y->lchild; 
  
    // Perform rotation 
    y->lchild = x; 
    x->rchild = T2; 
  
    findBalanceFactor(x);
    findBalanceFactor(y);
    return y; 
} 
nodeptr insert(nodeptr node, int data) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(createnode(data)); 
  
    if (data < node->data) 
        node->lchild  = insert(node->lchild, data); 
    else if (data > node->data) 
        node->rchild = insert(node->rchild, data); 
    else // Equal datas are not allowed in BST 
        return node; 
  
   	findBalanceFactor(node);
  
    
    // Left Left Case 
    if (node->bf > 1 && data < node->lchild->data) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (node->bf < -1 && data > node->rchild->data) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (node->bf > 1 && data > node->lchild->data) 
    { 
        node->lchild =  leftRotate(node->lchild); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (node->bf < -1 && data < node->rchild->data) 
    { 
        node->rchild = rightRotate(node->rchild); 
        return leftRotate(node); 
    } 
  	
    /* return the (unchanged) node pointer */
    return node; 
} 



void main()
{
	int x;
	nodeptr root=NULL;

	printf("Enter element for BST\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		root=insert(root,x);
		findBalanceFactor(root);
		preorderPrintBF(root);//BF=balance factor
		printf("Enter element for BST\n");
		scanf("%d",&x);
	}	
	
	return;
}
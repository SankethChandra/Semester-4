#include <stdio.h>
#include <stdlib.h>
#include "freefunc.h"
nodeptr q[100];
int f=0,r=0;
void createHeap(nodeptr temp, int key) 
{ 

  	q[r++]=temp;
    // Do level order traversal until we find 
    // an empty place.  
    while (r>f) { 
        nodeptr temp = q[f--];  
  
        if (!temp->lchild) { 
            temp->data = key;
            break; 
        } else
            q[r++]=temp->lchild; 
  
        if (!temp->rchild) { 
            temp->data = key; 
            break; 
        } else
            q[r++]=temp->rchild; 
   
    } 

} 


void main()
{
	int n;
	printf("Enter size of the array\n" );
	scanf("%d",&n);
	int a[n];
	printf("Enter elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	nodeptr root=NULL;
	for (int i=0;i<n;i++) 
	{
		createHeap(root,a[i]);
	}

 	inorder(root);
}										
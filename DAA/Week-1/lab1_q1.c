#include<stdio.h>
#include<stdlib.h>
typedef struct node * Nodeptr; 
typedef struct node{
	int data;
	Nodeptr right;
	Nodeptr left;
}NODE;

Nodeptr GetNode(int value){
	Nodeptr node=(Nodeptr)malloc(sizeof(NODE));
	node->left=NULL;
	node->right=NULL;
	node->data=value;
	return node;
}
Nodeptr InsertInto(Nodeptr root, int value){
	if(!root){
		root=GetNode(value);
	return root;
	}
	int c=root->data;
	if(value > c)
		root->right=InsertInto(root->right,value);
	else if(value < c)
		root->left=InsertInto(root->left,value);
	else 
		printf("*******Wrong option, this shouldn't happen*************\n");
return root;
}
Nodeptr SearchAndInsert(Nodeptr root, int value){
	if(root==NULL){
		printf("*********Key not found**********\n");
		root=InsertInto(root,value);
		printf("Inserted into binary tree \n");
		return root;
		}
		if(value==root->data){
			printf("**********Key is found in the tree***********\n");
		}
		else if(value > root->data){
			root->right=SearchAndInsert(root->right,value);
		}
		else if( value < root->data){
			root->left=SearchAndInsert(root->left,value);
		}
		else
			printf("*******Wrong option, this shouldn't happen*************\n");
return root;
}
void Inorder(Nodeptr root){
	if(root){
	Inorder(root->left);
	printf("%d\n",root->data );
	Inorder(root->right);
}
}
void Postorder(Nodeptr root){
if(root){
	Postorder(root->left);
	Postorder(root->right);
	printf("%d\n",root->data );
}
}
void preorder(Nodeptr root){
if(root){
	printf("%d\n",root->data );
	preorder(root->left);
	preorder(root->right);
}
}
void main(){
		int choice,value;
	Nodeptr root=NULL;
	do{
		printf("**************************\n");
		printf("Choose the following\n");
		printf("1.InsertInto binary search tree(*Required to execute other options)\n");
		printf("2.Search an element in binary search tree\n");
		printf("3.Inorder traversal\n");
		printf("4.Postorder traversal\n");
		printf("5.Preorder traversal\n");
		printf("6.Exit the Loop\n");
		scanf("%d",&choice);

		switch(choice){
			case 1:
			printf("Enter element to insert\n");
			scanf("%d",&value);
			while(value!=-1){
			root=InsertInto(root,value);
			printf("Enter element to insert\n");
			scanf("%d",&value);
			}
			printf("Insertion done succesfully\n");
			
			break;

			case 2:
			printf("Enter element to be searched\n");
			scanf("%d",&value);
			root=SearchAndInsert(root,value);
			printf("**********Process completed succesfully*********\n");
			break;

			case 3:
			printf("Inorder traversal\n");
			Inorder(root);
			break;

			case 4:
			printf("Postorder traversal\n");
			Postorder(root);
			break;

			case 5:
			printf("Preorder traversal\n");
			preorder(root);
			break;
		}
	}while(choice !=6);

printf("Bye friend\n");
}


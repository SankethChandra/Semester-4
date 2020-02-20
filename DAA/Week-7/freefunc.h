typedef struct node * nodeptr;
typedef struct node
{
nodeptr lchild;
nodeptr rchild;
int data;
int bf;//balance factor
}NODE;

nodeptr createnode(int d)
{
    nodeptr root=(nodeptr)malloc(sizeof(NODE));
    root->data=d;
    root->bf=0;//arbitarily.(changed by function written in lab7-q1
    return root;
}
nodeptr createbt(int x){
    if(x==-1)
    {
        printf("returning to \n");
        return NULL;
    }
    nodeptr root=createnode(x);
    int data;
    printf("Enter data into left child\n");
    scanf("%d",&data);
    root->lchild=createbt(data);
    printf("Enter data into right child\n");
    scanf("%d",&data);
    root->rchild=createbt(data);
    return root;
}
void inorder(nodeptr root)
{
    if(root){
        inorder(root->lchild);
        printf("%d\n",root->data);
        inorder(root->rchild);
    }
}
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
void preorderPrintBF(nodeptr root)
{
    if(root)
    {
	printf("node value %d\t balance factor %d\n",root->data,root->bf);        
	preorderPrintBF(root->lchild);
        preorderPrintBF(root->rchild);
    }
}

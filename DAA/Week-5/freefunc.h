typedef struct node * nodeptr;
typedef struct node
{
nodeptr lchild;
nodeptr rchild;
int data;
}NODE;

nodeptr createnode(int d)
{
    nodeptr root=(nodeptr)malloc(sizeof(NODE));
    root->data=d;
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
typedef struct node * nodeptr;
typedef struct node
{
nodeptr next;
int data;

}NODE;

nodeptr createnode(int d)
{
    nodeptr root=(nodeptr)malloc(sizeof(NODE));
    root->data=d;
     return root;
}
nodeptr insert(nodeptr root,int x)
{
    if(!root)
    {
        root=createnode(x);
        root->next=NULL;
        return root;
    }
    nodeptr temp=root;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=createnode(x);
    return root;
}
void PrintTable(nodeptr hashtable[],int n)
{
    int i=0;
    while(i !=n)
    {   
        printf("%d:\n",i);
        nodeptr temp=hashtable[i];
        while(temp)
        {

            printf("%d-> \t ",temp->data );
            temp=temp->next;
        }
        i++;
        printf("\n");
    }
}
void printList(nodeptr list)
{
    while(list)
    {
        printf("%d\t",list->data );
        list=list->next;
    }
    printf("\n");
}
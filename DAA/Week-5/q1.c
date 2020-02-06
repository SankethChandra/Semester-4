#include<stdio.h>
#include<stdlib.h>
int source,V,E,visited[20],G[20][20],pop[20],k=0;

void DFS(int i)
{
    int j;
    visited[i]=1;
    for(j=0;j<V;j++)
        if(G[i][j]==1 && visited[j]==0)
            DFS(j);
    pop[k]=i+1;
    k--;
}
void main()
{
    int i,j;
    printf("Enter adjaceny matrix size \n");
    scanf("%d",&V);
    k=V-1;
    printf("ENter adjacency matrix\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            scanf("%d",&G[i][j]);
    printf("Enter source\n");
    scanf("%d",&source);
    DFS(source-1);
    for(i=0;i<V;i++)
        if(visited[i]==0)
            DFS(i);
    printf("Topological sort order\n");
    for(i=0;i<V;i++)
        printf("%d\t",pop[i]);

}
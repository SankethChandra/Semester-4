#include <stdio.h>
#include <stdlib.h>
int opcount;
void hashit(int *hash,int key,int m)
{
int count,index=key%m;
		while(count!=m)
		{
			if(hash[index]==-1)
			{
				hash[index]=key;
				return;
			}
			else
				index++;
			count++;
		}
	
}
int hashsearch(int *hash,int key,int m)
{
	int count=0,index=key%m;
		while(count!=m)
		{
			opcount++;
			if(hash[index]==key)
				return index;
			else
				index++;
			count++;
		}
	return -1;
}

void main()
{
	int n,m;
	printf("Enter size of hash table\n");
	scanf("%d",&m);
	printf("Enter no of elements <=size of hash table\n");
	scanf("%d",&n);
	int* hash=(int *)calloc(m,sizeof(int));
	for(int i=0;i<m;i++)
		hash[i]=-1;
	int key;
	for(int i=0;i<n;i++)
	{
		printf("Enter key\n");
		scanf("%d",&key);
		hashit(hash,key,m);
	}
	printf("hash table\n");
	for(int j=0;j<m;j++)
		printf("%d\n",hash[j]);
	
	printf("Enter key to search\n");
	scanf("%d",&key);

	int pos=hashsearch(hash,key,m);
	if(pos!=-1)
		printf("found at %d\n opcount %d \n",pos,opcount );
	else
		printf("not found opcount %d\n",opcount );
}
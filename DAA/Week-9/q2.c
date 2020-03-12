#include <stdio.h>
#include <stdlib.h>
#include "freefunc.h"
#include <time.h>
int opcount;
int hashsearch(nodeptr hashl,int key)
{
	
	nodeptr temp=hashl;
	while(temp!=NULL)
	{
		opcount++;
		if(temp->data==key)
			return 1;
		else temp=temp->next;

	}
	return -1;//not found
}
void main()
{
	int m;
	printf("Enter size of hash table\n");
	scanf("%d",&m);
	//for simple hash table, hash funciton is mod m is used
	nodeptr hashtable[m];
	for(int i=0;i<m;i++)
		hashtable[i]=NULL;
	int count=0,n;
	printf("Enter no of keys\n");
	scanf("%d",&n);

	srand(time(0));
	//hashit now (also input is generated at random using rand function)
	//hash function can be changed but the hash value should be in 0-size

	while(count!=n)
	{	
		count++;
		int data=(int)random()%14353;
		hashtable[data%m]=insert(hashtable[data%m],data);
	}
	int key;
	printf("table\n");
	PrintTable(hashtable,m);
	//while(1){
	printf("\n\nEnter key to search\n");
	scanf("%d",&key);
	opcount=0;

	int flag=hashsearch(hashtable[key%m],key);
	if(flag!=-1)
		printf("element found opcount %d\n",opcount );
	else
		printf("element not found opcount %d\n",opcount);
	//}
}
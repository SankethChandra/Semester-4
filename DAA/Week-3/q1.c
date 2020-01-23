#include<stdio.h>
#include <time.h>
#include<stdlib.h>
void main(){
	int n,i,j,swap,opcount=0;
	srand(time(0));
	//printf("Enter the number of integers\n");
	n=random()%300;
	printf("%d,",n );
	int *a=(int*)calloc(n,sizeof(int));
	//printf("Entering elements into array using random\n");
	for(i=0;i<n;i++){
		a[i]=random()%1;
	}


	for(i=0;i<=n-2;i++){
		for(j=0;j<=n-2-i;j++){
			opcount++;//counts number of times the comparision is done
			if(a[j+1]<a[j]){
				swap=a[j];
				a[j]=a[j+1];
				a[j+1]=swap;
			}//if ends
		}//sort inner loop ends
	}//sort outer loop ends
//printf("\nPrinting sorted array\n");
/*for(i=0;i<n;i++){
	printf("%d\n",a[i] );
}
*/
printf("%d\n",opcount );
//program ends.
}


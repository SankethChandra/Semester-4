#include <stdio.h>

int gcd(int m,int n){
	int opcount=0;
int t;
if(m<n)
	t = m;
else 
	t= n;

	while(t>0){
		opcount++;
		if(m%t==0)
		{
			if(n%t==0){
				printf("Operation count: %d\n",opcount);
				return t;
			}
		}
		t--;
	}
}
void main(){
	int m,n;
	printf("Enter two numbers\n");
	scanf("%d %d",&m,&n);
	printf("GCD of these numbers is %d\n",gcd(m,n));
}
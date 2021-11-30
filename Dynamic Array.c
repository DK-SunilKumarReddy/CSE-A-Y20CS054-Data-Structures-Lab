#include<stdio.h>
#include<stdlib.h>

int* reverseArray(int[],int);
int main()
{
	int n,i,a[1000],*c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	c=reverseArray(a,n);
	for (i=0;i<n;i++)
	printf("%d ",c[i]);
}
int* reverseArray(int a[1000],int n)
{
	int i,*b,p=0;
	b=(int*)malloc(n*sizeof(int));
	for(i=n-1;i>=0;i--,p++)
	b[p]=a[i];
	return b;
}

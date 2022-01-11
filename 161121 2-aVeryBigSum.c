#include<stdio.h>
long int aVeryBigSum(int[],int);
int main()
{
    int n,a[10],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("%ld",aVeryBigSum(a,n));
}
long int aVeryBigSum(int a[10],int n)
{
    int i;
    long int s=0;
    for(i=0;i<n;i++)
    s=s+a[i];
    return s;
}

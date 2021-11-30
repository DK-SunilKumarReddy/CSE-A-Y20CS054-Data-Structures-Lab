#include<stdio.h>
#include<stdlib.h>
int main()
{
    long int *a,n,m,p,q,k,x=0,max=0,i;
    scanf("%ld%ld",&n,&m);
    a=(long int*)malloc((n+1)*sizeof(long int));
    for(i=1;i<=n;i++)
    a[i]=0;
    for(i=0;i<m;i++)
    {
        scanf("%ld%ld%ld",&p,&q,&k);
        a[p]=a[p]+k;
        if(q+1<=n)
        a[q+1]=a[q+1]-k;
    }
    for(i=1;i<=n;i++)
    {
        x=x+a[i];
        if(max<x)
        max=x;
    }
    printf("%ld",max);
}

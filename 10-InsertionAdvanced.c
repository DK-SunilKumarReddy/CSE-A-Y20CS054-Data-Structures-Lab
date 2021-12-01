#include<stdio.h>
#include<stdlib.h>
void merge(long int[],long int,long int);
void mSort(long int[],long int,long int);
long int c;
int main()
{
    long int t,i,j;
    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        long int n;
        c=0;
        scanf("%ld",&n);
        long int *a=(long int*)malloc(n*sizeof(long int));
        for(j=0;j<n;j++)
        scanf("%ld",&a[j]);
        mSort(a,0,n-1);
        printf("%ld\n",c);
    }
}
void mSort(long int a[],long int p,long int q)
{
    if(p<q)
    {
        mSort(a,p,(p+q)/2);
        mSort(a,((p+q)/2)+1,q);
        merge(a,p,q);
    }
}
void merge(long int a[],long int p,long int q)
{
    long int e=((p+q)/2)+1,f=q+1,s=p,k=0;
    long int *a2=(long int*)malloc((q-p+1)*sizeof(long int));
    q=e;
    for(k=0;p<e&&q<f;k++)
    {
        if(a[p]<=a[q])
        {
            a2[k]=a[p];
            p++;
        }
        else
        {
           a2[k]=a[q];
           c+=(e-p);
           q++; 
        }
    }
    for(;p<e;p++,k++)
    a2[k]=a[p];
    for(;q<f;q++,k++)
    a2[k]=a[q];
    for(k=0;s<f;s++,k++)
    a[s]=a2[k];
    free(a2);
}

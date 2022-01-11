#include <stdio.h>
void countSwaps(int,int[]);
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    countSwaps(n,a);
}
void countSwaps(int n,int a[n])
{
   int i,j,t,c=0;
   for(i=0;i<n;i++)
    for(j=0;j<n-1;j++)
    if(a[j]>a[j+1])
    {
    c++;
    t=a[j],a[j]=a[j+1],a[j+1]=t;
    }
   printf("Array is sorted in %d swaps.\n",c);
   printf("First Element: %d\n",a[0]);
   printf("Last Element: %d\n",a[n-1]);
}

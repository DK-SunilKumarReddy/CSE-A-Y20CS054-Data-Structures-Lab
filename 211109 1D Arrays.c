#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,*a,i,s=0;
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s=s+a[i];
    }
    printf("%d",s);
    free(a);
}

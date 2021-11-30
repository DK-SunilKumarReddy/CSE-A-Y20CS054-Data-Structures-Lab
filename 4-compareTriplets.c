#include<stdio.h>
int* compareTriplets(int[],int[]);
int main()
{
    int a[3],b[3],*c,i;
    for(i=0;i<3;i++)
    scanf("%d",&a[i]);
    for(i=0;i<3;i++)
    scanf("%d",&b[i]);
    c=compareTriplets(a,b);
    printf("%d %d",c[0],c[1]);
}
int* compareTriplets(int a[3],int b[3])
{
    int *c=(int*)malloc(sizeof(int)),i;
    c[0]=c[1]=0;
    for(i=0;i<3;i++)
    {
        if(a[i]>b[i])
        c[0]=c[0]+1;
        else if(a[i]<b[i])
        c[1]=c[1]+1;
    }
    return c;
}

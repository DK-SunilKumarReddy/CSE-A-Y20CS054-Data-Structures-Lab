#include<stdio.h>
#include<stdlib.h>
int *cq,n,f=-1,r=-1;
int isEmpty()
{
    if(f==-1 && r==-1)
    return 1;
    return 0;
}
int isFull()
{
    if(f==(r+1)%n)
    return 1;
    return 0;
}
void insert()
{
    if(isFull())
    {
        printf("Queue is full\n");
        return;
    }
    int e;
    printf("Enter element to insert:");
    scanf("%d",&e);
    if(f==-1 && r==-1)
    f++;
    r=(r+1)%n;
    cq[r]=e;
}
void delete()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    int t=cq[f];
    if(f==r)
    f=r=-1;
    else
    f=(f+1)%n;
    printf("Deleted element is %d\n",t);
}
void printQueue()
{
    for(int i=f;;i=((i+1)%n))
    {
    printf("%d\t",cq[i]);
    if(i==r)
    break;
    }
    printf("\n");
}
int main()
{
    printf("Enter size of the circular queue:");
    scanf("%d",&n);
    cq=(int*)malloc(n*sizeof(int));
    printf("Enter 1 to insert 2 to delete,3 to print,any other key to exit\n");
    char k;
    while(1)
    {
        scanf(" %c",&k);
        if(k=='1')
        insert();
        else if(k=='2')
        delete();
        else if(k=='3')
        printQueue();
        else
        return 0;
    }
}

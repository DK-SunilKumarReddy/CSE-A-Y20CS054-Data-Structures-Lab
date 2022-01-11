#include<stdio.h>
#include<stdlib.h>
typedef struct hashing
{
    int d;
    struct hashing* next;
}hn;
int hash(int k,int l)
{
    int i;
    i=k%l;
    return i;
}
hn* createNode()
{
    hn*t=(hn*)malloc(sizeof(hn));
    int data;
    scanf("%d",&data);
    t->d=data;
    t->next=NULL;
    return t;
}
hn* delete(int l,int e,hn* head[l])
{
    int i;
    hn* t1,*t2,*t3;
    i=hash(e,l);
        t1=head[i];
        while(t1!=NULL)
        {
            if(e==t1->d)
            {
                if(t1==head[i])
                t3=head[i],head[i]=head[i]->next,free(t3);
                else
                t2->next=t1->next,free(t1);
                return head[l];
            }
            t2=t1;
            t1=t1->next;
        }
    printf("Element not found\n");
    return head[l];
}
void insert(int l,int e2,hn*head[l])
{
    int i=hash(e2,l),j;
    hn* newn=(hn*)malloc(sizeof(hn)),*t=head[i];
    newn->d=e2;
    newn->next=head[i];
    head[i]=newn;
}
void search(int l,int e2,hn*head[l])
{
    int i=hash(e2,l),j;
    hn* t=head[i];
    while(t)
    {
        if(t->d==e2)
        {
        printf("Element found at hashindex %d\n",i);
        return;
        }
        t=t->next;
    }
    printf("Element not found\n");
}
void display(int l,hn*head[l])
{
    int i;
    hn*t;
    for(i=0;i<l;i++)
    {
        t=head[i];
        while(t!=NULL)
        {
            printf("%d  ",t->d);
            t=t->next;
        }
        printf("\n");
    }
}
int main()
{
    int i,l,e,k;
    printf("Enter hashtable size:");
    scanf("%d",&l);
    if(l<=0)
    return 0;
    hn* head[l];
    for(i=0;i<l;i++)
    head[i]=NULL;
    while(1)
    {
        printf("Enter 1 to insert,2 to delete,3 to search, 4 to print,0 to exit:");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            {
                printf("Enter element to insert:");
                scanf("%d",&e);
                insert(l,e,head);
                break;
            }
            case 2:
            {
                printf("Enter element to delete:");
                scanf("%d",&e);
                head[l]=delete(l,e,head);
                break;
            }
            case 3:
            {
                printf("Enter element to search:");
                scanf("%d",&e);
                search(l,e,head);
                break;
            }
            case 4:
            {
                display(l,head);
                break;
            }
            default:exit(0);
        }
    }
}

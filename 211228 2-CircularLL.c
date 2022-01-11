#include<stdio.h>
#include<stdlib.h>
typedef struct cllnode
{
    int d;
    struct cllnode*next;
}cn;
cn* createNode()
{
    int d;
    cn*t=(cn*)malloc(sizeof(cn));
    scanf("%d",&d);
    t->d=d;
    t->next=NULL;
    return t;
}
cn* createList(int l)
{
    int i;
    cn *head=NULL,*last,*newn;
    for(i=0;i<l;i++)
    {
        newn=createNode();
        if(i==0)head=newn;
        else last->next=newn;
        last=newn;
    }
    last->next=head;
    return head;
}
void printList(cn*h)
{
    cn*t=h;
    if(!t)return;
    while(t->next!=h)
    {
        printf("%d\t",t->d);
        t=t->next;
    }
    printf("%d",t->d);
}
int length(cn*h)
{
    cn* t=h;
    int c=1;
    while(t->next!=h)
    {
        c++;
        t=t->next;
    }
    return c;
}
cn* delete(cn*head,int e)
{
    cn*h=head,*t=head,*t2;
    while(t->next!=head)
    t=t->next;
    if(head->d==e)
    {
    t->next=head->next;
    free(head);
    head=t->next;
    return head;
    }
    while(h->next!=head)
    {
        if(h->next->d==e)
        {
         t2=h->next;
        h->next=h->next->next;
        free(t2);
        return head;
        }
        h=h->next;
    }
    printf("Element not found\n");
    return head;
}
cn* insert(cn*head,int p,int e,int l)
{
    int i;
    cn* h=head,*t=head;
    cn*nn=(cn*)malloc(sizeof(cn));
    nn->d=e;
    nn->next=NULL;
    if(p<1||p>l+1)
    {
        printf("Invalid position entered\n");
        return head;
    }
    while(t->next!=h)
     t=t->next;
    if(p==1)
    {
      nn->next=head;
      head=nn;
      t->next=head;
      return head;
    }
    for(i=1;i<p-1;i++)
     h=h->next;
     if(p==l+1)nn->next=head;
     else nn->next=h->next;
     h->next=nn;
     return head;
}
int main()
{
    int l,p,e,k;
    cn*h;
    printf("enter size\n");
    scanf("%d",&l);
    printf("Enter elements\n");
    h=createList(l);
    while(1)
    {
        printf("Enter 1 to insert, 2 to delete, 3 to print list, 0 to exit:");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            {
                printf("Enter position and element to insert\n");
                scanf("%d%d",&p,&e);
                l=length(h);
                h=insert(h,p,e,l);
                break;
            }
            case 2:
            {
                printf("Enter element to delete\n");
                scanf("%d",&e);
                h=delete(h,e);
                break;
            }
            case 3:
            {
                printList(h);
                break;
            }
            default:exit(0);
        }
    }
}

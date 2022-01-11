#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode()
{
    int data;
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&data);
    t->data=data;
    t->next=NULL;
    return t;
}
struct Node* createList(int l)
{
    int i;
    struct Node*head=NULL,*last,*newn;
    for(i=0;i<l;i++)
    {
        newn=createNode();
        if(i==0)head=newn;
        else last->next=newn;
        last=newn;
    }
    return head;
}
struct Node* reverse(struct Node*rl)
{
    struct Node* t=rl,*p,*c=NULL;
    while(t)
    p=c,c=t,t=t->next,c->next=p;
    rl=c;
    return rl;
}
struct Node* order(struct Node*h)
{
    struct Node*t1=h,*p,*t2,*t3,*rl;
    int f=0,c=0;
    while(t1)
    {
        if(t1->data%2==0)
        {
            if(f==0)
            {
                if(t1!=h)
                t3=p;
                t2=t1;
            }
            f=1;
            c+=1;
        }
        else
        f=0;
        if(f==0 && c>1)
        {
            p->next=NULL;
            rl=reverse(t2);
            if(t2!=h)t3->next=rl;
            else h=rl;
            while(rl->next)
            rl=rl->next;
            rl->next=t1;
            c=0;
        }
        else if(c>1 && t1->next==NULL)
        {
           rl=reverse(t2);
            if(t2==h)h=rl;
            else t3->next=rl;
            return h;
        }
        p=t1;
        t1=t1->next;
    }
    return h;
}
int main()
{
    int l;
    struct Node* h;
    printf("Enter size:");
    scanf("%d",&l);
    printf("Enter elements\n");
    h=createList(l);
    h=order(h);
    printf("After rearranging\n");
    while(h!=NULL)
    {
        printf("%d\t",h->data);
        h=h->next;
    }
}

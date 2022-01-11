#include<stdio.h>
#include<stdlib.h>
typedef struct polynomialterm
{
    int coef,exp;
    struct polynomialterm *next;
}pt;
void display(pt*);
pt* createNode()
{
    int c,e;
    pt* t;
    scanf("%d%d",&c,&e);
    t=(pt*)malloc(sizeof(pt));
    t->coef=c;
    t->exp=e;
    t->next=NULL;
    return t;
}
pt* createList(int l)
{
    int i;
    pt* newn,*head=NULL,*last;
    for(i=0;i<l;i++)
    {
        newn=createNode();
        if(i==0)head=newn;
        else
        last->next=newn;
        last=newn;
    }
    return head;
}
pt* multiply(pt*m1,pt*m2)
{
	pt* m=(pt*)malloc(sizeof(pt)),*t=m,*t3,*h=m2;
	if(m1==NULL)
	return NULL;
	else if(m2==NULL)
	return NULL;
	while(m1)
	{
		h=m2;
		while(h)
		{
			t->exp=m1->exp+h->exp;
			t->coef=m1->coef*h->coef;
			h=h->next;
			t->next=(pt*)malloc(sizeof(pt));
			t3=t;
			t=t->next;	
		}
		m1=m1->next;
	}
	free(t);
	t3->next=NULL;
	return m;
}
pt* sort(pt*m)
{
	pt*t=m,*t3;
	int l=0,i,j,t1,t2;
	while(t)
	{
		l++;
		t=t->next;
	}
	t=m;
	for(i=0;i<l-1;i++)
	{
		t=m;
		for(j=0;j<l-i-1;j++)
		{
			if(t->exp<t->next->exp)
			{
				t1=t->coef,t->coef=t->next->coef,t->next->coef=t1;
                t2=t->exp,t->exp=t->next->exp,t->next->exp=t2;
            }
            else if(t->exp==t->next->exp)
            {
            	t->coef+=t->next->coef;
				t3=t->next;
            	t->next=t->next->next;
				free(t3);
            	l--;
            }
			t=t->next;
		}
	}
	return m;
}
void display(pt * list)
{
	if(list==NULL)
	printf("%dX^%d",0,0);
	while(list!=NULL)
	{
		printf("%dX^%d",list->coef,list->exp);
		if(list->next!=NULL)
		printf(" + ");
		list=list->next;
	}
	printf("\n\n");
}
int main()
{
    int l1,l2;
    pt* m1,*m2,*m;
    printf("Enter no. of terms in polynomial 1\n");
    scanf("%d",&l1);
    printf("Enter terms with coefficient,exponent accordingly\n");
  m1=sort(createList(l1));
    printf("Enter no. of terms in polynomial 2\n");
    scanf("%d",&l2);
    printf("Enter terms with coefficient,exponent accordingly\n");
    m2=sort(createList(l2));
    m=sort(multiply(m1,m2));
    printf("polynomial 1:\n");
    display(m1);
    printf("polynomial 2:\n");
    display(m2);
    printf("Resultant polynomial after multiplying:\n");
    display(m);
}

#include<stdio.h>
#include<stdlib.h>
typedef struct polynomialterm
{
    int coef,exp;
    struct polynomialterm *next;
}pt;
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
pt* sortList(pt* h,int l)
{
    int i,j,t1,t2;
    pt* t=h,*t3;
    for(i=0;i<l-1;i++)
    {
        t=h;
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
                t->next=t3->next;
                free(t3);
                l--;
            }
            t=t->next;
        }
    }
    return h;
}
pt* addPolynomial(pt*s1,pt*s2)
{
  pt* s=(pt*)malloc(sizeof(pt)),*t=s,*t2;
  if(s1==NULL)
  return  s2;
  if(s2==NULL)
  return s1;
  while(s1&&s2)
  {
  	if(s2->exp>s1->exp)
  	{
  		t->coef=s2->coef;
  		t->exp=s2->exp;
  		s2=s2->next;
  	}
  	else if(s2->exp<s1->exp)
  	{
  		t->coef=s1->coef;
  		t->exp=s1->exp;
  		s1=s1->next;
  	}
  	else
  	{
  		t->coef=s1->coef+s2->coef;
  		t->exp=s1->exp;
  		s1=s1->next;
  		s2=s2->next;
  	}
  	t->next=(pt*)malloc(sizeof(pt));
  	t2=t;
  	t=t->next;
  }
  free(t);
  if(s1!=NULL)
  t2->next=s1;
  else if(s2!=NULL)
  t2->next=s2;
  else
  t2->next=NULL;
  return s;
}
void display(pt * list)
{
	while(list!=NULL)
	{
		printf("%dX^%d",list->coef,list->exp);
		if(list->next!=NULL)
		printf(" + ");
		else printf("\n\n");
		list=list->next;
	}
}
int main()
{
    int l1,l2;
    pt* s1,*s2,*s;
    printf("Enter no. of terms in polynomial 1\n");
    scanf("%d",&l1);
    printf("Enter terms with coefficient,exponent accordingly\n");
   s1=sortList(createList(l1),l1);
    printf("Enter no. of terms in polynomial 2\n");
    scanf("%d",&l2);
    printf("Enter terms with coefficient,exponent accordingly\n");
    s2=sortList(createList(l2),l2);
    s=addPolynomial(s1,s2);
    printf("polynomial 1:\n");
    display(s1);
    printf("polynomial 2:\n");
    display(s2);
    printf("Resultant plolynomial after adding:\n");
    display(s);
}

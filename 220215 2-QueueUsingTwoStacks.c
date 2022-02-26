#include <stdio.h>
#include <stdlib.h>
int *x,*y;
int t1=-1,t2=-1;
int main()
{
    int *x,*y;
    int t1=-1,t2=-1;
    x=(int*)malloc(100000*sizeof(int));
    y=(int*)malloc(100000*sizeof(int));
    int q,i,k,e;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&k);
        if(k==1)
        {
            scanf("%d",&e);
            t1=t1+1;
            x[t1]=e;
        }
        else if(k==2)
        {
            while(t1!=-1)
            {
                t2=t2+1;
                y[t2]=x[t1];
                t1=t1-1;
            }
            t2=t2-1;
            while(t2!=-1)
            {
                t1=t1+1;
                x[t1]=y[t2];
                t2=t2-1;
            }
        }
        else 
        printf("%d\n",x[0]);
    }
}

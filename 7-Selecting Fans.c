#include<stdio.h>
#include<string.h>
int main()
{
    int n,t,i,j;
    scanf("%d%d",&n,&t);
    int a[n],p;
    char k[30],s[n][30];
    for(i=0;i<n;i++)
    {
    scanf("%s",s[i]);
    scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
            if(a[j]<a[j+1])
            {
                p=a[j],a[j]=a[j+1],a[j+1]=p;
                strcpy(k,s[j]),strcpy(s[j],s[j+1]),strcpy(s[j+1],k);
            }
    }
    for(i=0;i<t;i++)
    {
        if(a[i]>a[i+1])
        printf("%s\n",s[i]);
        else if(a[i]==a[i+1])
        {
            if(strcmp(s[i],s[i+1])<=0)
                printf("%s\n",s[i]);
        }
    }
}

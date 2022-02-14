#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int calc(int a,int b,char c)
{
    if(c=='+')
    return a+b;
    else if(c=='-')
    return a-b;
    else if(c=='*')
    return a*b;
    else if(c=='/')
    return a/b;
    else if(c=='^')
    return pow(a,b);
    else
    {printf("Invalid expression\n");exit(0);}
}
int main()
{
    int i,l,top=-1;
    char *e=(char*)malloc(50*sizeof(char));
    printf("Enter postfix expression:");
    scanf("%[^\n]",e);
    l=strlen(e);
    int *s=(int*)malloc(l*sizeof(int));
    for(i=0;i<l;i+=2)
    {
        if(e[i]>='0'&&e[i]<='9')
        top++,s[top]=e[i]-'0';
        else
        {
            if(top==-1 || top==0){printf("Invalid expression\n");return 0;}
            top--;
            s[top]=calc(s[top],s[top+1],e[i]);
        }
    }
    if(top!=0){printf("Invalid expression\n");return 0;}
    printf("Solution=%d",s[top]);
    free(s),free(e);
}

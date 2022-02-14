#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,l,t,top=-1,z=0;
    char *e,*s,*p;
    e=(char*)malloc(50*sizeof(char));
    printf("Enter infix expression:");
    scanf("%s",e);
     l=strlen(e);
    s=(char*)malloc((l+1)*sizeof(char));
    p=(char*)malloc((l+1)*sizeof(char));
    for(i=0;i<l;i++)
    {
        if(e[i]>='a'&&e[i]<='z' || e[i]>='A'&&e[i]<='Z')
        s[z]=e[i],z++;
        else if(e[i]=='+' || e[i]=='-')
        {
            while(top!=-1&&p[top]!='(')
            s[z]=p[top],z++,top--;
            top++,p[top]=e[i];
        }
        else if(e[i]=='*'||e[i]=='/')
        {
             while(top!=-1&&p[top]!='('&&p[top]!='+'&&p[top]!='-')
             s[z]=p[top],z++,top--;
             top++,p[top]=e[i];
        }
        else if(e[i]=='(')
        top++,p[top]=e[i];
        else if(e[i]==')')
        {
            if(top==-1)
            {printf("Invalid expression\n");return 0;}
            while(p[top]!='(')
            {
                s[z]=p[top],z++;
                top--;
            if(top==-1)
            {printf("Invalid expression\n");return 0;}
             }
             top--;
        }
        else if(e[i]=='^')
         top++,p[top]=e[i];
        else
        { printf("Invalid expression\n");return 0; }
    }
    while(top!=-1)
    {
        if(p[top]=='(')
        { printf("Invalid expression\n"); return 0; }
        s[z]=p[top],z++;
        top--;
    }
    printf("Postfix expression is\n");
    for(i=0;i<z;i++)
    printf("%c",s[i]);
    free(e),free(s),free(p);
}

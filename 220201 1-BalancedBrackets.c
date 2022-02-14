char* isBalanced(char* s) {
int l=strlen(s),i,top=-1;
if(s[0]==')'||s[0]==']'||s[0]=='}')
return "NO";
char* t=(char*)malloc(l*sizeof(char));
for(i=0;i<l;i++)
{
    if(s[i]=='('||s[i]=='['||s[i]=='{')
    {
        top=top+1;
        t[top]=s[i];
    }
    else {
       if(s[i]==')'&&t[top]!='(')
       return "NO";
       if(s[i]==']'&&t[top]!='[')
       return "NO";
       if(s[i]=='}'&&t[top]!='{')
       return "NO";
       top=top-1;
    }
}
if(top!=-1)
return "NO";
free(t);
return "YES";
}

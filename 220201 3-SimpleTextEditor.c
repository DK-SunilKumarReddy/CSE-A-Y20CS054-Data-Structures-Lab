#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char **s;
int z=0;
void append()
{
    char *w=(char*)malloc(1000000*sizeof(char));
    scanf("%s",w);
    int l=strlen(w);
    s[z]=(char*)malloc((l+strlen(s[z-1])+1)*sizeof(char));
    strcpy(s[z],s[z-1]);
    strcat(s[z],w);
    z++;
    free(w);
}
void del()
{
    int k,j,l;
    scanf("%d",&k);
    l=strlen(s[z-1]);
    s[z]=(char*)malloc((l+1)*sizeof(char));
    l=l-k;
    strcpy(s[z],s[z-1]);
    s[z][l]='\0';
    z++;
}
void print()
{
    int g;
    scanf("%d",&g);
    printf("%c\n",s[z-1][g-1]);
}
void undo()
{
    z--;
}
int main() {
int q,i,t;
scanf("%d",&q);
s=(char**)malloc((q+1)*sizeof(char*));
s[z]=(char*)malloc(2*sizeof(char));
strcpy(s[z],"");
z++;
for(i=0;i<q;i++)
{
    scanf("%d",&t);
    if(t==1)
    append();
    else if(t==2)
    del();
    else if(t==3)
    print();
    else
    undo();
}
free(s);
}

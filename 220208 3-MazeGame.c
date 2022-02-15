#include<stdio.h>
#include<stdlib.h>
int **a,*s1,*s2,top=0,x,y,m,n;
void findcord(int d,int e)
{
    if(d+1<m&&a[d+1][e]==1)//south 
    x=d+1,y=e;
    else if(d+1<m&&e+1<n&&a[d+1][e+1]==1)//south east
    x=d+1,y=e+1;
    else if(e+1<n&&a[d][e+1]==1)//east
    x=d,y=e+1;
    else if(d-1>=0&&e+1<n&&a[d-1][e+1]==1)//north east
    x=d-1,y=e+1;
    else if(d-1>=0&&a[d-1][e]==1)//north
    x=d-1,y=e;
    else if(d-1>=0&&e-1>=0&&a[d-1][e-1]==1)//north west
    x=d-1,y=e-1;
    else if(e-1>=0&&a[d][e-1]==1)//west
    x=d,y=e-1;
    else if(d+1<m&&e-1>=0&&a[d+1][e-1]==1)//south west
    x=d+1,y=e-1;
    else
    x=-1,y=-1;
}
void printpath()
{
    for(int i=0;i<=top;i++)
    printf("(%d,%d)-",s1[i],s2[i]);
}
int main()
{
    int i,j,g,h;
    printf("Enter dimensions of maze:");
    scanf("%d%d",&m,&n);
    a=(int**)malloc(m*sizeof(int*));
    s1=(int*)malloc(m*n*sizeof(int));
    s2=(int*)malloc(m*n*sizeof(int));
    s1[0]=0,s2[0]=0;
    printf("Enter binaries:\n");
    for(i=0;i<m;i++)
    {
    a[i]=(int*)malloc(n*sizeof(int));
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    }
    printf("Enter destination coordinates:");
    scanf("%d%d",&g,&h);
    if(g>=m||h>=n||a[g][h]==0)
    {printf("Path cannot be found\n");return 0;}
    while(top!=-1)
    {
        findcord(s1[top],s2[top]);
        if(x==-1)
        top--;
        else
        top++,s1[top]=x,s2[top]=y,a[x][y]=0;
        if(s1[top]==g&&s2[top]==h)
        {
            printf("Path found,Path is:\n");
            printpath();
            return 0;
        }
    }
    printf("Path not found\n");
}

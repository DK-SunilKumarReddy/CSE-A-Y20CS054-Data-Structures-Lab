#include <stdio.h>
int hourglassSum(int [][6]);
int main()
{
    int i,j,a[6][6];
    for(i=0;i<6;i++)
    for(j=0;j<6;j++)
    scanf("%d",&a[i][j]);
    printf("%d",hourglassSum(a));
}
int hourglassSum(int a[6][6])
{
    int i,j,b[16],c[16],d[16],s[16],k=0,m;
    for(i=0;i<4;i++)
    {
    for(j=0;j<4;j++)
    {
    b[k]=a[i][j]+a[i][j+1]+a[i][j+2];
    k++;
    }
    }
    k=0;
    for(i=2;i<6;i++)
    {
    for(j=0;j<4;j++)
    {
    c[k]=a[i][j]+a[i][j+1]+a[i][j+2];
    k++;
    }
    }
    k=0;
    for(i=1;i<5;i++)
    {
    for(j=1;j<5;j++)
    {
    d[k]=a[i][j];
    k++;
    }
    }
    for(i=0;i<16;i++)
    s[i]=b[i]+c[i]+d[i];
    m=s[0];
    for(i=1;i<16;i++)
    {
        if(m<s[i])
        m=s[i];
    }
    return m;
    
}

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
if (h1_count==0 || h2_count==0 || h3_count==0)
return 0;
int i,top1=0,top2=0,top3=0,c1=0,c2=0,c3=0;
    for(i=0;i<h1_count;i++)
    c1=c1+h1[i];
    for(i=0;i<h2_count;i++)
    c2=c2+h2[i];
    for(i=0;i<h3_count;i++)
    c3=c3+h3[i];
  while(1)
  {
      if(c1==c2&&c2==c3)
      return c1;
      if(c1>=c2&&c1>=c3)
      {
          c1=c1-h1[top1];
          top1=top1+1;
      }
      else if(c2>=c3&&c2>=c1)
      {
          c2=c2-h2[top2];
          top2=top2+1;
      }
      else
      {
          c3=c3-h3[top3];
          top3=top3+1;
      }
  }
  return 0;
}

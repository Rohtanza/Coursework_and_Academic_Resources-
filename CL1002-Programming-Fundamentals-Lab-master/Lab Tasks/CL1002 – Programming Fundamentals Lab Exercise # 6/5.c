#include<stdio.h>
int main()
  {
    int x,i,sum,D;
    printf("Enter the number");
    scanf("%d",&x);
    for (i=x;i>x;i--)
    {
      D=x%i;
      if(D==0)
      sum=D+sum;
    }
    if(sum==x)
    printf("Perfect");
    else
    printf("no");
    return 0;}

#include<stdio.h>
int main()
{
    int num,count=0;
    printf("\nEnter the num:");
    scanf("%d",&num);
    while (num>0)
      {
        num=num/10;
        count++;
        }
       printf("\ndigits in the number are %d\n",count);
       return 0;}    


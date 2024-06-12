#include<stdio.h>
 int HCF(int x, int y);
 int main()
 {
 int x, y;
printf("\nEnter x:");
scanf("%d",&x);
printf("\nEnter y:");
scanf("%d",&y);
printf("\nHCF is \"%d\"\n",HCF(x,y));
return 0;
}


int HCF(int x, int y)
{
int d;
    for (int z=1;z<=x&&z<=y;z++)
    {
     if(x%z==0&&y%z==0)
       {
       d=z;
       }
    }
return d;
}   


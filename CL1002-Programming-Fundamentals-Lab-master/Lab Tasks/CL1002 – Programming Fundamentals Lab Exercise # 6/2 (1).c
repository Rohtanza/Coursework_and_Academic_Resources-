#include<stdio.h>
int LCM(int x,int y);
int main()
{ 
int x, y;
printf("\nenter x: "); 
scanf("%d",&x);
printf("\nenter y: "); 
scanf("%d",&y);
printf("\nLCM is \"%d\" ",LCM(x,y));
return 0;}
int LCM(int x, int y)
 { int z;
   if (x > y)
   {z=x;}
   else
   {z=y;}
   while (1) 
      { 
        if (z % x == 0 && z % y == 0) 
       {  break; 
        } 
        ++z; }
  return z;
  }


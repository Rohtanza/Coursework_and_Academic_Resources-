//Program to examin Greatest odd number and determin the nature to numbers.
//Program detects if none of them is odd and show relative output.
#include<stdio.h>
int main()
{
     int x,y,z;
     printf("\nEnter the 1st number x :");
     scanf("%d",&x);
     printf("\nEnter the 2nd number y :");
     scanf("%d",&y);
     printf("\nEnter the 3rd number z :");
     scanf("%d",&z);
     
if(x%2!=0||y%2!=0||z%2!=0)
// Determining if any of input is odd.
// If one of them is odd them determing the Greatest one.
  {
     if(x%2==0)
     {x=0;}
     if(y%2==0)
     {y=0;}
     if(z%2==0)
     {z=0;}
     if(x>y && x>y)
     {printf("\n%d is the greatest odd number among them.\n\n",x);}
     else if( y>x && y>z)
     {printf("\n%d is the greatest odd number among them.\n\n",y);}
     else
     {printf("\n%d is the greastest odd number among them.\n\n",z);}
     
  }
// If none of them is odd then the following output is shown.     
else
  {
      printf("\nNone of them is odd\n\n");
  }
  
return 0;}
























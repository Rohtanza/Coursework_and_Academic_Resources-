#include<stdio.h>
int main()
{
	 int number,i, rem=0;
	 printf("Enter number: ");
	 scanf("%d", &number);
	
	 for(i=0;i < number; i++)
	 {
	  rem = rem+i;
	
	  if(rem == number)
	  {
	   printf("%d is TRIANGULAR NUMBER.", number);
	   break;
	  }
	 }
	
	 if(number == i)
	 {
	  printf("%d is NOT TRIANGULAR NUMBER.", number);
	 }
	 return 0;
}
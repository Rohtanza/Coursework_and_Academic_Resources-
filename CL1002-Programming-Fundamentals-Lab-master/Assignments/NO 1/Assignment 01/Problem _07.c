//Program to Calculate the Cost of Fax service.
#include<stdio.h>
// Defining Constants to use in Prgram.
#define servicecharge 3.00
#define charge1 0.20
// Charge1 is for first ten pages.
#define charge2 0.10
// Charge2 is for pages other then the first ten pages.
#define limit 10
float ChargeCal(float Pages);
//Function to Calculate cost.
int main()
{
float Pages;
printf("Enter the pages: ");
scanf("%f",&Pages);
printf("\nThe total charge of faxed services on \"%.0f\" pages is : %.2f$ \n\n",Pages,ChargeCal(Pages));
return 0;
}
float ChargeCal (float Pages)
{
  if(Pages<=limit)
  //Checking if pages are equal or less then 10.
  return (servicecharge+(Pages*charge1));
  else
  {
  float AmountDue,Page1,Page2;
  //Page1 is pages after the frist ten pages.
  //Page2 is frist then pages.
  Page1=Pages-limit;
  Page2=Pages-Page1;
  AmountDue=((Page2*charge1)+(Page1*charge2)+servicecharge);
  return AmountDue;
  }
}

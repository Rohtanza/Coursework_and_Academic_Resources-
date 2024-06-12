//Program to Check whether is leap or not.
#include<stdio.h>
void isleap(int year);
int main()
{
int year;
printf("\nEnter the year : ");
scanf("%d",&year);
isleap(year);
return 0;
}
void isleap(int year)
//Above funtion will determine weather a year is leap or not.
//Using nested if-else.
{
//Checking if its a century year
if (year%100==0)
{
//if its a Century year then it's divisible by 400.
    if(year%400==0)
    {    
    printf("\n%d is leap year.\n\n",year);
    }
else
    {
    printf("\n%d isn't a leap year.\n\n",year);
    }
}
else
{
//if it aint a Century year then it's divisible by 4.
    if(year%4==0)
    {
    printf("\n%d is a leap yaer.\n\n",year);
    }
    else
    {
    printf("\n%d is not a leap year.\n\n",year);
    }
}}


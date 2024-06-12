//Converts Celsius to Fahrenheit
/*Float is been used instead of int
beacuse of Accuracy and Precision.
& caculation is limited in int.
and C to F conversion gives
result in decimal point*/
#include<stdio.h>
float celsiusToFahrenheit(float celsius);
int main()
{
float celsius;
printf("\nEnter the Celsius value: ");
scanf("%f",&celsius);
//Calling function inside of printf to improve code efficency
printf("\nThe Value in Fahrenheit is: %.2f F\n\n",celsiusToFahrenheit(celsius));
return 0;
}
// A Function which converts Celsius to Fahrenheiit.
float celsiusToFahrenheit(float celsius)
{
return (celsius*9/5+32);
}


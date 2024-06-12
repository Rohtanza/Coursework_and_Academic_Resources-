//EarthQuick mangitude range checker.
//Program is pretty much simple.
//Using "if" and rucursion of "else if" to read ranges.
#include<stdio.h>
int main()
{
float read;
printf("\nEnter the reading:");
scanf("%f",&read);
// Reading Magnitudes using relational operators.
if(read<2.0)
{printf("\nMagnitude \"%.1f\" earthquake is considered to be a Micro earthquake.\n\n",read);}
else if(read==2.0||read<3.0)
{printf("\nMagnitude \"%.1f\" earthquake is considered to be a very minor earthquake.\n\n",read);}
else if(read==3.0||read<4.0)
{printf("\nMagnitude \"%.1f\" earthquake is considered to be a Minor earthquake.\n\n",read);}
else if(read==4.0||read<5.0)
{printf("\nMagnitude \"%.1f\" earthquake is considered to be a Light earthquake.\n\n",read);}
else if(read==5.0||read<6.0)
{printf("\nMagnitude \"%.1f\" earthquake is considered to be a Moderate earthquake.\n\n",read);}
else if(read==6.0||read<7.0)
{printf("\nMagnitude \"%.1f\" earthquake is considered to be a Strong earthquake.\n\n",read);}
else if(read==7.0||read<8.0)
{printf("\nMagnitude \"%.1f\" earthquake is considered to be a Major earthquake.\n\n",read);}
else if(read==8.0||read<10.0)
{printf("\nMagnitude \"%.1f\" earthquake is considered to be a Great earthquake.\n\n",read);}
else if(read>=10.0)
{printf("\nMagnitude \"%.1f\" earthquake is considered to be a Meteoric earthquake.\n\n",read);}
else 
return 0;
}


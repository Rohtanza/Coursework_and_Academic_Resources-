// Code is Created by Muhammad Rehan 22P-9106.
#include<stdio.h>
void pattren(int num,int choice);
int main()
{
  int num,choice;
  printf("1:\n");pattren(5,1);printf("\n2:\n");pattren(5,2);
  printf("\nChoice your pattren (\"1\":for downwards & \"2\":for upwards):");scanf("%d",&choice);
  printf("\nEnter the number of Row till you want to print the pattren :");scanf("%d",&num);printf("\n\n");printf("--------------\nYour Diagram:\n--------------\n\n");
  pattren(num,choice);
  printf("\n");
  return 0;
}
void pattren(int num,int choice)
{ 
  if (choice==1)
   {int row,col;int n=num;
   for (row=0;row<n;row++)
     {
        int space=row;
        for(space=0;space<row;space++ )     
          {printf(" ");}
        
         for(col=0;col<n-row;col++) 
          {printf("*");}
         printf("\n");
     }}
     else
     {
     int n=num,row,col,space;
    for (row=1;row<=n;row++)
    {
    for(space=n-row;space>0;space--)
    {printf(" ");}
    for(col=1;col<=row;col++)
    {printf("*");}
    printf("\n");}
     }}

  


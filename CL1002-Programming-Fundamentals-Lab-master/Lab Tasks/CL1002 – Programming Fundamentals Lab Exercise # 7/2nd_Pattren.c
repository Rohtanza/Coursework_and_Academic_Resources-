// Code is Created by Muhammad Rehan 22P-9106.
#include<stdio.h>
int main()
{
  int num,row,col;char element;
  printf("\nEnter the element (e.g. @, - ^, *, | , #, $):");scanf("%c",&element);
  printf("\nEnter the numbers of rows:");scanf("%d",&num);printf("\n");
  for (row=1;row<(2*num);row++)
  {
    int cols=row>num?2*num-row:row;
    for(col=0;col<cols;col++)
    { 
      printf("%c",element);
      }
  
    printf("\n");
  }
return 0;
}

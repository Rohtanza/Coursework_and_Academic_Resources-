//Program to Calculate Cookies,Boxes and Containers Shipment.
#include<stdio.h>
int BoxCal(int Cookies,int NumOfBox);
//Above Function will Calculate Boxes and leftover Cookies.
int ConCal(int Box,int NumOfCon);
//Above Function will Calculate Containers and leftover Boxes.
int main()
{
    int Cookies,NumOfBox,NumOfCon,Box,Con;
    printf("\nEnter the Number of Cookies: ");
    scanf("%d",&Cookies);
    printf("\nEnter the Numbers of Cookies in a Box: ");
    scanf("%d",&NumOfBox);
    printf("\nEnter the numbers of boxes in a Containers: ");
    scanf("%d",&NumOfCon);
    printf("\nSHIPPING DETIALS:\n");
    Box=BoxCal(Cookies,NumOfBox);
   printf("\nThe \"%d\" cookies will require \"%d\" boxe(s) to be shipped.\n",Cookies,Box);
    Con=ConCal(Box,NumOfCon);
     printf("\nThe \"%d\" Boxes will require \"%d\" container(s) to be shipped.\n\n",Box,Con);

return 0;}
int BoxCal(int Cookies,int NumOfBox)
{
   int boxes,leftover;
   // Calculating Boxes to be shipped.
   boxes=Cookies/NumOfBox;
   // Calculating Leftcover Cookies.
   leftover=Cookies%NumOfBox;
   printf("\nThe number of leftover cookies is: \"%d\"\n",leftover);
   return boxes;
   // Returning boxes to main to be printed.
}
int ConCal(int Box, int NumOfCon)
{
 if (NumOfCon>Box)
 {printf("\nThe Number of Boxes are less then the boxes limit for container so no container will be shipped.\n");
 return 0;}
 else
 {int contain,leftoverbox;
 // Calculating Containers to be shipped.
 contain=Box/NumOfCon;
 // Calculating Leftover Boxes.
 leftoverbox=Box%NumOfCon;
 printf("\nThe number of leftover boxes are: \"%d\"\n",leftoverbox);
 return contain;
 // returning Containers to main to be printed.
 }}
 

//Program to check if triangle is equilateral, isosceles or scalene.
#include<stdio.h>
void TriangleChecker(int x,int y,int z);
//Above Function checks the type of Triangle.
int main()
{ 
    int x,y,z;
    printf("\nEnter the Values of Triangale:\nx:");
    scanf("%d",&x);
    printf("y:");
    scanf("%d",&y);
    printf("z:");
    scanf("%d",&z);
    TriangleChecker(x,y,z);
    return 0;}
    
    void TriangleChecker(int x,int y,int z)
    {
       if(x==y&&y==z&&x==z)
       // Checking if all sides are equal.
         {printf("Equilateral triangle.\n\n");}
       if(x!=y&&y!=z&&x!=z)
       // Checking is all sides are unequal.
         {printf("Scalene triangle.\n\n");}
       if(x==y&&x!=z||x==z&&x!=y||y==z&&y!=x)
       // Checking if one two of sides are equal.
         {printf("Issoceles triangle.\n\n");}
     }


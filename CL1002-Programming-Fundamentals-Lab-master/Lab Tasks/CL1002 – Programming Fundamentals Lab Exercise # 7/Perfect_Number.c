// Code is Created by Muhammad Rehan 22P-9106.
#include <stdio.h>
int Perfect(int num);
int main()
{
   int limit, num = 1;
   printf("\nEnter the range till where you want to print perfect numbers : ");
   scanf("%d", &limit);printf("\n");
   for (int i = 1; i <= limit; i++)
   {
      if (Perfect(num) == 1)
      {
         printf("=> %04d", i);
         printf("\n");
      }
      num++;
   }
   printf("\n");return 0;
}
int Perfect(int num)
{
   int sum = 0;
   for (int i = 1; i < num; ++i)
   {
      if (num % i == 0)
      {
         sum = sum + i;
      }
   }
   if (sum == num)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

#include <stdio.h>
#include <stdlib.h>
int *arraycreation(); 
void unionset(int *Setone, int *Settwo, int ArrayOnesize, int ArrayTwosize, int
union_size, int result[]); 
int arraysize; 
int main(void) 
{ 
 printf("Enter the elements of Set One (-1 to stop):\n"); 
 int *Setone = arraycreation(); 
 int ArrayOnesize = arraysize; 
 printf("Enter the elements of Set Two (-1 to stop):\n"); 
 int *Settwo = arraycreation(); 
 int ArrayTwosize = arraysize; 
 int same = 0; 
 for (int i = 0; i < ArrayOnesize; i++) 
 { 
 for (int j = 0; j < ArrayTwosize; j++) 
 if (Setone[i] == Settwo[j]) 
 same++; 
 } 
 int union_size = (ArrayOnesize + ArrayTwosize) - same; 
 int result[union_size]; 
 unionset(Setone, Settwo, ArrayOnesize, ArrayTwosize, union_size, result); 
 return 0; 
} 
int *arraycreation() 
{ 
 int *Numbers = NULL; 
 size_t NumberOfAllocatedElements = 0; 
 int TemporaryNumber; 
 int j = 1; 
 arraysize = 0; 
 while (786) 
 { 
 printf("Enter the number no %d : ", j++); 
 scanf("%d", &TemporaryNumber); 
 if (TemporaryNumber == -1) 
 break; 
 int *NewNumbers = realloc(Numbers, ++NumberOfAllocatedElements * sizeof
*NewNumbers); 
 if (!NewNumbers) 
 { 
 fprintf(stderr, "Error, unable to allocate memory.\n"); 
 exit(EXIT_FAILURE); 
 } 
 Numbers = NewNumbers; 
 Numbers[NumberOfAllocatedElements - 1] = TemporaryNumber; 
 arraysize++; 
 } 
 j = 0; 
 return Numbers; 
} 
void unionset(int *Setone, int *Settwo, int ArrayOnesize, int ArrayTwosize, int
union_size, int result[]) 
{ 
 int i = 0, j = 0, x = 0, count = ArrayOnesize, flag = 1; 
 for (i = 0; i < ArrayOnesize; i++) 
 { 
 result[i] = Setone[i]; 
 } 
 for (i = 0; i < ArrayTwosize; i++) 
 { 
 flag = 1; 
 x = 0; 
 for (j = 0; flag == 1 && j < ArrayOnesize; j++) 
 { 
 if (Setone[j] == Settwo[i]) 
 { 
 flag = 0; 
 } 
 } 
 if (flag == 1) 
 { 
 result[count] = Settwo[i]; 
 count++; 
 } 
 } 
 printf("Vettore generato:\n"); 
 for (i = 0; i < count; i++) 
 printf(" %d ", result[i]); 
 return ; 
} 
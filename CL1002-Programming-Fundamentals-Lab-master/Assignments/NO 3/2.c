#include <stdio.h>
int main() 
{ 
 int R_one, R_two, C_one, C_two; 
 printf("Enter the Row and Coloum of Matrix One :"); 
 scanf("%d %d", &R_one, &C_one); 
 printf("Enter the Row and Coloum of Matrix Two :"); 
 scanf("%d %d", &R_two, &C_two); 
 if (C_one != R_two) 
 { 
 puts("\nCan't Multiply because Row of Matrix one isn't equal to Colume of Matrix 
two.\n"); 
 return 1; 
 } 
 int MatrixOne[R_one][C_one]; 
 int MatrixTwo[R_two][C_two]; 
 int Result[R_one][C_two]; 
 puts("Enter Matrix One:"); 
 for (int i = 0; i < R_one; i++) 
 { 
 for (int j = 0; j < C_one; j++) 
 { 
 printf("\tEnter the Element of Row:%d and Col:%d: ", (i + 1), (j + 1)); 
 scanf("%d", &MatrixOne[i][j]); 
 } 
 } 
 puts("Enter Matrix Two:"); 
 for (int i = 0; i < R_two; i++) 
 { 
 for (int j = 0; j < C_two; j++) 
 { 
 printf("\tEnter the Element of Row:%d and Col:%d: ", (i + 1), (j + 1)); 
 scanf("%d", &MatrixTwo[i][j]); 
 } 
 } 
 for (int i = 0; i < R_one; i++) 
 { 
 for (int j = 0; j < C_two; j++) 
 { 
 Result[i][j] = 0; 
 for (int k = 0; k < C_one; k++) 
 { 
 Result[i][j] += MatrixOne[i][k] * MatrixTwo[k][j]; 
 } 
 } 
 } 
 puts("Here's the Resultant Matric:\n"); 
 for (int i = 0; i < R_one; i++) 
 { 
 for (int j = 0; j < C_two; j++) 
 { 
 printf(" | %2d", Result[i][j]); 
 } 
 printf("| \n"); 
 } 
 return 0; 
}
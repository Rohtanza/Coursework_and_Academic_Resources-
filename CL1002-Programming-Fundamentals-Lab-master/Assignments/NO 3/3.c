#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float CGPA(char **grades, float points[]); 
int main() 
{ 
 char *grades[] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F"}; 
 float points[] = {4.0, 3.67, 3.33, 3.0, 2.67, 2.33, 2.0, 1.67, 1.33, 1.0, 0}; 
 printf("The CPGA is %.2f : ", CGPA(grades, points)); 
 return 0; 
} 
float CGPA(char **grades, float points[]) 
{ 
 int Subject; 
 float gradepoints, point,credit_hour_sum; 
 credit_hour_sum = gradepoints = 0; 
 printf("Enter the count of the Subjects : "); 
 scanf("%d", &Subject); 
 for (int i = 0; i < Subject; i++) 
 { 
 char grade[3]; 
 int j = 0; 
 float credit_hour; 
 printf("\nEnter Subject no \'%d\' :", (i + 1)); 
 scanf("%s", grade); 
 printf("\nEnter the Credit hour of The Subject no \'%d\' :", (i + 1)); 
 scanf("%f", &credit_hour); 
 while (1) 
 { 
 if (strcmp(grades[j], grade) == 0) 
 { 
 point = points[j]; 
 break; 
 } 
 j++; 
 if (j > 11) 
 { 
 puts("Enter a valid Grade\nTry Again"); 
 exit(1); 
 } 
 } 
 gradepoints = gradepoints + (point * credit_hour); 
 credit_hour_sum += credit_hour; 
 } 
 return (gradepoints / credit_hour_sum); 
} 
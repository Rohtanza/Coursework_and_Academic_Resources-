//Code Created by Muhammad Rehan, 22P-9106, BSSE 1A,
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void operations(char string[], int size);
void vowel(char string[], int size);
void vandc(char string[], int size);
void Frechar(char string[], int size);
void Cont(char string[], int size);
int main()
{
    char string[50];
    puts("Enter the sting:");
    scanf("%s", string);
    int size = strlen(string);
    operations(string, size);
    return 0;
}
void operations(char string[], int size)
{

    printf("\nEnter the option:\nA) Count the number of vowels in the string\nB) Count both the vowels and consonants in the string.\nC) Display the most frequent character in the string.\nD) Concatenate another string with the existing string.\nE) Exit the program.");
    char option;
    printf("\nEnter option:");
    scanf("\n%c", &option);
    switch (option)
    {
    case 'A':
        vowel(string, size);
        break;
    case 'a':
        vowel(string, size);
        break;
    case 'B':
        vandc(string, size);
        break;
    case 'b':
        vandc(string, size);
        break;
    case 'C':
        Frechar(string, size);
        break;
    case 'c':
        Frechar(string, size);
        break;
    case 'D':
        Cont(string, size);
        break;
    case 'd':
        Cont(string, size);
        break;
    case 'E':
        exit(1);
        break;
    case 'e':
        exit(1);
        break;
    default:
        puts("\nEnter a valid input.\n");
        break;
    }
}
void vowel(char string[], int size)
{
    int count = 0;
    char vow[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (string[i] == vow[j])
                count++;
        }
    }
    printf("\nThe count of vowels in the string is %d\n", count);
    operations(string, size);
}
void vandc(char string[], int size)
{
    int count = 0;
    char vow[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (string[i] == vow[j])
                count++;
        }
    }
    printf("\nThe vowels are %d and the consonants are %d\n", count, size - count);
    operations(string, size);
}
void Frechar(char string[], int size)
{
    char character = string[0];
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (string[i] == string[j])
            {
                count++;
                if (count > sum)
                {
                    sum = count;
                    character = string[i];
                }
            }
        }
    }
    if (count == 1)
    {
        printf("\nThe frequency of all characters are same.\n");
    }
    else
    {
        printf("\nThe Most Frequent Charcter is %c\n", character);
    }
    operations(string, size);
}

void Cont(char string[], int size)
{
    char co[50];
    puts("Enter you string:");
    scanf("%50s", co);
    printf("\n%s \n",strcat(strcat(string," "),co));
    operations(string, size);
}
#include <stdio.h>
#include <string.h>
void palindrome(char name[]);
char reserve();
int main()
{
    char name[50];
    puts("Enter the name:");
    scanf("%s",name);
    palindrome(name);
    return 0;
}
void palindrome(char name[])
{
    int equal;
    int size = strlen(name);
    char reserve[50];
    for (int i = 0; i < size; i++)
    {
        reserve[i] = name[(size - i) - 1];
    }
    printf("\nThe reserve of the name is :%s", reserve);
    equal=strcmp(name, reserve);
    if (equal == 0)
    {      
        puts("\nThe name is palindrome\n");
    }
    else
    {
        puts("\nThe name isn't palindrome\n");
    }
}
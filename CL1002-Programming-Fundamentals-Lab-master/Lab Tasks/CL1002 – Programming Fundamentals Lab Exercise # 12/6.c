// Muhammad Rehan, 22P-9106,BSE-1A
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100
int main()
{
    srand(time(NULL));
    int *Hun;
    Hun = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        *(Hun + i) = rand() % size;
    }
    for (int x = 0; x < size; x++)
    {
        for (int y = x + 1; y < size; y++)
        {
            if (*(Hun + x) < *(Hun + y))
            {
                int temp = *(Hun + x);
                *(Hun + x) = *(Hun + y);
                *(Hun + y) = temp;
            }
        }
    }
    FILE *fp = NULL;
    fp = fopen("sortedNumbers.txt", "w");
    if (fp == NULL)
    {
        puts("Cant open file");
        return 1;
    }
    for (int j = 0; j < size; j++)
    {
        fprintf(fp, "%d\n", *(Hun + j));
    }
    if (fclose(fp) == 0)
        puts("File is created and data is wriiten check the file\nPress 1 to read file");
    free(Hun);
    int flag = 0;
    scanf("%d", &flag);
    if (flag)
    {
        FILE *fr = NULL;
        fr = fopen("sortedNumbers.txt", "r");
        char c;
        puts("File starts here");
        while ((c = fgetc(fr)) != EOF)
        {
            printf("%c", c);
        }
    }
    return 0;
}
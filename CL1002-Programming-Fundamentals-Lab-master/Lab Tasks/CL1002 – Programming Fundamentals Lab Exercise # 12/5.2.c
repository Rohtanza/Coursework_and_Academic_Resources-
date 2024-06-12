#include <stdio.h>
int main()
{
    FILE *fr = NULL;
    fr = fopen("names.txt", "r");
    if (fr == NULL)
    {
        puts("cant open file");
        return 1;
    }
    int character, line;
    line = character = 0;
    char c;
    while ((c = fgetc(fr)) != EOF)
    {
        if (c == '\n')
            line++;
        else
            character++;
    }
    printf("The sum of lengths are :%d\nThe lines are %d:", character, line);
    fclose(fr);
    return 0;
}

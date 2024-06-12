//Muhammad Rehan, 22P-9106,BSE-1A
/*This is generic code keep writing anything you like, 
just type quit when you want to finish wriiting and 
it will keep save it in a file and it will show you the file in the end*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define buffer_size 1024
int main()
{
    bool keepgoing = true;
    char buffer[buffer_size];
    FILE *f;
    f = fopen("firstfile.txt", "w");
    while (keepgoing)
    {
        fgets(buffer, buffer_size, stdin);
        if (strcmp(buffer, "quit\n") == 0)
            keepgoing = false;
        else
            fputs(buffer, f);
    }
    if (fclose(f) == 0)
    {
        puts("file is closed");
    };
    FILE *fr;
    fr = fopen("firstfile.txt", "r");
    if (fr == NULL)
        puts("cant open file");
    else
    {
        puts("file is open");
    }
    char c;
    while ((c = fgetc(fr)) != EOF)
    {
        printf("%c", c);
    }
    fclose(fr);
    return 0;
}
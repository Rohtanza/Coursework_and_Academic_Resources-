#include <stdio.h>
int main()
{
    FILE *fr, *fw = NULL;
    fr = fopen("names.txt", "r");
    fw = fopen("name_subj.txt", "w");
    if (fr == NULL)
    {
        puts("CANT OPEN FILE.");
        return 1;
    }
    if (fw == NULL)
    {
        puts("CANT WRITE FILE.");
        return 1;
    }
    int line=1;
    char name[100];
    char subject[] = "Programming Fundaments,Calculus,English Compisiton";
    while (!feof(fr))
    {
        fscanf(fr, "%s", name);
        fprintf(fw, "%d %s,%s\n",line, name, subject);
        line++;
    }
    fclose(fr);
    fclose(fw);
    return 0;
}
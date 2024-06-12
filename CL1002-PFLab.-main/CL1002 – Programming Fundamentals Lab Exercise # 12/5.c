//Muhammad Rehan, 22P-9106,BSE-1A
#include <stdio.h>
void print(int limit, FILE *fr);
int main()
{
    printf("1.Print the first 4 character of every name in a file (names.txt)\n2.Prints the sum of the lengths of the names in names.txt.\n3.Read names in names.txt to a given length,\n4.Reads names in names.txt and writes out a file at name_subj.txt containing the names along with subject’s name, one per line, in the corresponding order.\n");
    int option;
    printf("\nEnter your option:");
    scanf("%d", &option);
    if (option == 1)
    {
        FILE *fr = NULL;
        fr = fopen("names.txt", "r");
        if (fr == NULL)
        {
            puts("Cant open file");
            return 1;
        }
        char n[3];
        char c;
        while (fscanf(fr, "\n%3s\n", n) == 1)
        {
            printf("%3s\n", n);
            while ((c = fgetc(fr)) != '\n')
            {
            }
        }
        fclose(fr);
    }
    if (option == 2)
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
        printf("The sum of lengths are :%d\nThe lines are :%d\n\n", character, line);
        fclose(fr);
    }
    if (option == 3)
    {
        int limit;
        int line = 0;
        printf("Enter the number till you want to print:");
        scanf("%d", &limit);
        FILE *fr = NULL;
        fr = fopen("names.txt", "r");
        if (fr == NULL)
        {
            puts("CANT open file");
            return 1;
        }
        print(limit, fr);
        if (fclose(fr) != 0)
            puts("couldnt open file");
    }
    if (option == 4)
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
        int line = 1;
        char name[100];
        char subject[] = "Programming Fundaments,Calculus,English Compisiton";
        while (!feof(fr))
        {
            fscanf(fr, "%s", name);
            fprintf(fw, "%d %s,%s\n", line, name, subject);
            line++;
        }
        fclose(fr);
        fclose(fw);
        puts("Your file is created and written as CVS File");
    }
    return 0;
}
void print(int limit, FILE *fr)
{
    int line = 0;
    char name[100];
    while (!feof(fr))
    {
        if (line > limit - 1)
            break;
        fgets(name, 100, fr);
        printf("%s", name);
        line++;
    }
}
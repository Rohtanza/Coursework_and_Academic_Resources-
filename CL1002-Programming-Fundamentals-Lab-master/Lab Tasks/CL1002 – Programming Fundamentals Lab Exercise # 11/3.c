k// Code Written by Muhammad Rehan 22P-9106 BSE 1A
// This code run on smaller letter and
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void operation(char foo[], char option);
void encrypt(char foo[]);
void decrypt(char foo[]);
int main()
{
    char foo[50];
    puts("Enter the secret message:");
    fgets(foo, sizeof(foo), stdin);
    puts("Enter option:\nA) Encrpytion of the message.\nB) Decrption of the meesege.");
    char option;
    scanf("%c", &option);
    operation(foo, option);
    return 0;
}
void operation(char foo[], char option)
{
    switch (option)
    {
    case 'A':
        encrypt(foo);
        break;
    case 'a':
        encrypt(foo);
        break;
    case 'B':
        decrypt(foo);
        break;
    case 'b':
        decrypt(foo);
        break;
    default:
        break;
    }
}
void encrypt(char foo[])
{
    int i;
    int len = strlen(foo);
    char encrypt[len];
    for (i = 0; i < len - 1; i++)
    {
        int spacechecker = isspace(foo[i]);
        if (spacechecker != 0)
        {
            encrypt[i] = ' ';
        }
        else
        {
            encrypt[i] = foo[i] + 3;
        }
    }
    for (int j = 0; j < len; j++)
    {
        int spacechecker = isspace(encrypt[j]);
        if (encrypt[0] >= 65 && encrypt[len - 2] <= 96)
        {
            if (encrypt[j] >= 90)
            {
                if (spacechecker != 0)
                {
                    encrypt[j] = ' ';
                }
                else
                {
                    encrypt[j] = encrypt[j] - 26;
                }
            }
        }
        else
        {
            if (encrypt[j] >= 122)
            {
                if (spacechecker != 0)
                {
                    encrypt[j] = ' ';
                }
                else
                {
                    encrypt[j] = encrypt[j] - 26;
                }
            }
        }
    }
    printf("%s", encrypt);
}
void decrypt(char foo[])
{
    int i;
    int len = strlen(foo);
    char dencrypt[len];
    for (i = 0; i < len - 1; i++)
    {
        int spacechecker = isspace(foo[i]);
        if (spacechecker != 0)
        {
            dencrypt[i] = ' ';
        }
        else
        {
            dencrypt[i] = foo[i] - 3;
        }
    }

    for (int j = 0; j < len-1; j++)
    {
        int spacechecker = isspace(dencrypt[j]);
        if (dencrypt[0] >= 65 && dencrypt[len - 2] <= 90)
        {
            if (dencrypt[j] <= 65)
            {
                if (spacechecker != 0)
                {
                    dencrypt[j] = ' ';
                }
                else
                {
                    dencrypt[j] = dencrypt[j] + 26;
                }
            }
        }
        else
        {
            if (dencrypt[j] <= 97)
            {
                if (spacechecker != 0)
                {
                    dencrypt[j] = ' ';
                }
                else
                {
                    dencrypt[j] = dencrypt[j] + 26;
                }
            }
        }
    }
    printf("%s", dencrypt);
}

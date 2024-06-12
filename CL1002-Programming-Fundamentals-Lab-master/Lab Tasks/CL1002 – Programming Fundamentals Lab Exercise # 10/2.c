#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int Sum[11] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int count[11] = {0};
    srand(time(NULL));
    int range = (12 - 2 + 1) + 2;
    for (int i = 0; i < 1000; i++)
    {
        if (rand() % range + rand() % range == Sum[0])
            count[0]=count[0]+1;
        if (rand() % range + rand() % range == Sum[1])
            count[1]=count[1]+1;
        if (rand() % range + rand() % range == Sum[2])
            count[2]=count[2]+1;
        if (rand() % range + rand() % range == Sum[3])
            count[3]=count[3]+1;
        if (rand() % range + rand() % range == Sum[4])
            count[4]=count[4]+1;
        if (rand() % range + rand() % range == Sum[5])
            count[5]=count[5]+1;
        if (rand() % range + rand() % range == Sum[6])
            count[6]=count[6]+1;
        if (rand() % range + rand() % range == Sum[7])
            count[7]=count[7]+1;
        if (rand() % range + rand() % range == Sum[8])
            count[8]=count[8]+1;
        if (rand() % range + rand() % range == Sum[9])
            count[9]=count[9]+1;
        if (rand() % range + rand() % range == Sum[10])
            count[10]=count[10]+1;
    }
    printf("Combination\tFrequency");
    for (int i = 0; i < 11; i++)
    {
        printf("\t\t\n%d\t\t%d\n", Sum[i],count[i]);
    }
    return 0;
}
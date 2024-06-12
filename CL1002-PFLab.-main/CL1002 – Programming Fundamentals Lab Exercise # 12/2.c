//Muhammad Rehan, 22P-9106,BSE-1A
#include <stdio.h>
int main()
{
    int talbe_num,Limit;
    int *table_pointer,*Limit_pointer;
    table_pointer=&talbe_num;
    Limit_pointer=&Limit;
    printf("Enter the Table Number:");
    scanf("%d",table_pointer);
    printf("Enter the limit:");
    scanf("%d",Limit_pointer);
    for (int i = 0; i < *Limit_pointer; i++)
    {
        printf("%d * %d = %d\n",*table_pointer,(i+1),((i+1)*(*table_pointer*1)));
    }
    return 0;
}
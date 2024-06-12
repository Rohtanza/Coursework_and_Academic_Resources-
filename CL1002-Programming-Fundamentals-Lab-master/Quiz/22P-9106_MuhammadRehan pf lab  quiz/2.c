#include <stdio.h>
int main()
{
    //written by muhammad rehan p22-9106
   int num;
    printf("enter the number:");
    scanf("%d", &num);
    int fst, Snd, Tr3d, Frd;
    fst = num / 1000;
    Snd = (num / 100) % 10;
    Tr3d = (num / 10) % 10;
    Frd = num % 10;
    // In the above step i am seprating the digits 
    // printf("%d\n%d\n%d\n%d\n", fst, Snd, Tr3d, Frd);// This was for my own testing
    // this was for testing that ive seperated the digits right way 
    fst = (fst + 7 )% 10;
    Snd = (Snd + 7) % 10;
    Tr3d = (Tr3d + 7) % 10;
    Frd = (Frd + 7 )% 10;
    // Applying the encryption
    printf("\nthe enrypted form of %d is %d%d%d%d\n",num, Tr3d, Frd, fst, Snd);
    //Printing the digits accordingto the right way of displaying the encrypted way.
    return 0;
}
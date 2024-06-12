#include <stdio.h>
int main()
{
    int loan_amount;
    printf("the the loan amount:");
    scanf("%d", &loan_amount);
    int monthly;
    printf("the the monlthly amount:");
    scanf("%d", &monthly);
    float interset;
    printf("the the interset :");
    scanf("%f", &interset);
    float intersetmonth = (interset / 12) / loan_amount;
    printf("the\n%f:", intersetmonth);
    int m;
    while (loan_amount > 0)
    {
        int permonth = loan_amount*intersetmonth;
        printf("the month insterset are %.0f\n", permonth);
        int principal = monthly - intersetmonth;
        printf("the month are %d\n", principal);
        monthly = loan_amount - principal;
        loan_amount=loan_amount-monthly;
        printf("the left are %d\n", loan_amount);
        m++;
    }

    return 0;
}

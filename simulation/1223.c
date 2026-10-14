#include <stdio.h>

int main(void)
{
    char isbn[14];
    while (scanf("%s", isbn) == 1)
    {
        int sum = 0;
        sum += (isbn[0] - '0') * 1;
        
        for (int i = 2; i < 5; i++)
        {
            sum += (isbn[i] - '0') * i;
        }
        
        for (int i = 6; i < 11; i++)
        {
            sum += (isbn[i] - '0') * (i - 1);
        }
        
        int mod = sum % 11;
        
        if (mod == isbn[12] - '0' || (mod == 10 && isbn[12] == 'X'))
        {
            printf("Right\n\n");
        }
        else
        {
            if (mod == 10)
            {
                printf("%.11s-X", isbn);
            }
            else
            {
            printf("%.11s-%d\n\n", isbn, mod);
            }
        }
    }
    return 0;
}
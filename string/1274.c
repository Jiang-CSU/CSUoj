#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    char str[201];
    while (scanf("%s", str) == 1)
    {
        bool flag = true;
        int length = strlen(str);
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] < 48 || str[i] > 57)
            {
                flag = false;
            }
        }
        
        if (length < 6)
        {
            flag = false;
        }
        
        if (flag)
        {
            printf("msg-");
            for (int i = length - 6; str[i] != '\0'; i++)
            {
                printf("%c", str[i]);
            }
            printf("\n");
        }
        else
        {
            printf("Wrong Message!\n");
        }
    }
    return 0;
}
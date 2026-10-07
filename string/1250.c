#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isReversed(char str[], int length);
bool isPrime(int number);

int main(void)
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
    {
        int count = 0;
        for (int i = a; i <= b; i++)
        {
            char str[5];
            snprintf(str, sizeof(str), "%d", i);
            int length = strlen(str);
            if (isReversed(str, length) && isPrime(i))
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}

bool isReversed(char str[], int length)
{
    char reversed[5];
    for (int i = 0; i < length; i++)
    {
        reversed[i] = str[length - 1 - i];
    }
    
    reversed[length] = '\0';
    
    if (strcmp(str, reversed))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool isPrime(int number)
{
    if (number == 1)
    {
        return false;
    }
    
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    
    return true;
}
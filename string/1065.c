#include <stdio.h>
#include <string.h>

void compareASCII(char[][1001], int);
void compareLength(char[][1001], int);

int main(void)
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        char numbers[n + 1][1001];
        
        for (int i = 0; i < n; i++)
        {
            scanf("%s", numbers[i]);
        }
        
        compareASCII(numbers, n);
        compareLength(numbers, n);
        
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", numbers[i]);
        }
        
    }
    return 0;
}

void compareASCII(char numbers[][1001], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(numbers[j], numbers[j + 1]) > 0)
            {
                char temp[1001];
                strcpy(temp, numbers[j + 1]);
                strcpy(numbers[j + 1], numbers[j]);
                strcpy(numbers[j], temp);
            }
        }
    }
}

void compareLength(char numbers[][1001], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strlen(numbers[j]) > strlen(numbers[j + 1]))
            {
                char temp[1001];
                strcpy(temp, numbers[j + 1]);
                strcpy(numbers[j + 1], numbers[j]);
                strcpy(numbers[j], temp);
            }
        }
    }
}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAo(char str[], int length);

int main(void)
{
    int N;
    scanf("%d", &N);
    
    while (N--)
    {
        int a, b;
        int total = 0;
        
        scanf("%d %d", &a, &b);
        for (int i = a; i <= b; i++)
        {
            char str[8];
            snprintf(str, sizeof(str), "%d", i);
            int length = strlen(str);
            if (isAo(str, length))
            {
                total += 1;
            }
            
        }
        
        printf("%d\n", total);
    }
    
    return 0;
}

bool isAo(char str[], int length)
{
    if (length < 3)
    {
    return false;
    }

    int record[length - 1];
    int count = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (str[i] > str[i + 1])
        {
            record[i] = -1;
        }
        else if (str[i] < str[i + 1])
        {
            record[i] = 1;
        }
        else
        { 
            return false;
        }
    }
    
    for (int j = 0; j < length - 2; j++)
    {
        if (record[j] != record[j + 1] && record[0] == -1)
        {
            count += 1;
        }
    }
    
    if (count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
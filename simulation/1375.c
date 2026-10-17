#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isReversed(char key[], int start, int len);

int main(void)
{
    char key[1001];
    
    while (scanf("%s", key) == 1)
    {
        int length = strlen(key);
        bool flag = false;
        
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (isReversed(key, j, length - i))
                {
                    printf("%d\n", length - i);
                    flag = true;
                    break;
                }
            }
            
            if (flag)
            {
                break;
            }
        }
    }
    return 0;
}

bool isReversed(char key[], int start, int len)
{
    for (int i = start; i < start + len / 2; i++)
    {
        if (key[i] != key[2 * start + len - i - 1])
        {
            return false;
        }
    }
    
    return true;
}
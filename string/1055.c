#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int isReversed(char str[], int length);
bool isMirrored(char str[], int length);

int main(void)
{
    char str[51];
    
    while (scanf("%s", str) == 1)
    {
        int length = strlen(str);
        if (isReversed(str, length) == 1)
        {
            printf("%s -- is a regular palindrome.\n\n", str);
        }
        else if (isReversed(str, length) == 2)
        {
            printf("%s -- is a mirrored palindrome.\n\n", str);
        }
        else
        {
            if (isMirrored(str, length))
            {
                printf("%s -- is a mirrored string.\n\n", str);
            }
            else
            {
                printf("%s -- is not a palindrome.\n\n", str);
            }
        }
    }
    return 0;
}

int isReversed(char str[], int length)
{
    char mirror[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y', '1', '8'};
    
    if (length == 1)
    {
        for (int j = 0; j < 13; j++)
        {
            if (str[0] == mirror[j])
            {
                return 2;
            }
        }
        return 1;
    }
    
    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - 1 -i])
        {
            return 0;
        }
    }
    
    for (int i = 0; i < (length + 1) / 2; i++)
    {
        bool flag = false;
        for (int j = 0; j < 13; j++)
        {
            if (str[i] == mirror[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            return 1;
        }
    }

    return 2;
}

bool isMirrored(char str[], int length)
{
    char mirrorNum[] = {'E', 'Z', 'S', 'J', 'L', '2', '5', '3'};
    char mirror[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y', '1', '8'};
    
    for (int i = 0; i < (length + 1) / 2; i++)
    {
        bool flag = false;
        if (str[i] != str[length - 1 -i])
        {
            for (int j = 0; j < 8; j++)
            {
                if (str[i] == mirrorNum[j] && str[length - 1 - i] == mirrorNum[7 - j])
                {
                    flag = true;
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < 13; j++)
            {
                if (str[i] == mirror[j])
                {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            return false;
        }
    }
    return true;
}

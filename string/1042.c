#include <stdio.h>
#include <string.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        char str[1000];
        scanf("%s", str);
        char minStr = str[0];
        char newStr[1000] = "";
        char currStr[1000];
        strcpy(currStr, str);
        
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] <= minStr)
            {
                minStr = str[i];
                int index = i;
                int j;
                int k;
                
                for (j = 0; str[index] != '\0'; j++)
                {
                    newStr[j] = str[index++];
                }
                
                for (k = 0 ; k < i; k++)
                {
                    newStr[k + j] = str[k];
                }
                
                newStr[k + j] = '\0';
                
                if (strcmp(newStr, currStr) < 0)
                {
                    strcpy(currStr, newStr);
                }
            }
        }
        
        printf("%s\n", currStr);
    }

    return 0;
};
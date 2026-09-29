#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char str[42];
    char command;
    
    fgets(str, sizeof(str), stdin);
    scanf("%c", &command);
    
    if (command == 'D')
    {
        bool flag = true;
        char secondCommand;
        scanf(" %c", &secondCommand);
        
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == secondCommand)
            {
                for (int j = i; j < strlen(str); j++)
                {
                    str[j] = str[j + 1];
                }
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            printf("Not exist");
        }
        else
        {
            printf("%s", str);
        }
    }
    
    if (command == 'I')
    {
        bool flag = true;
        char secondCommand, thirdCommand;
        scanf(" %c %c", &secondCommand, &thirdCommand);
        for (int i = strlen(str) - 2; i >= 0; i--)
        {
            if (str[i] == secondCommand)
            {
                for (int j = strlen(str); j >= i; j--)
                {
                    str[j + 1] = str[j];
                }
                str[i] = thirdCommand;
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            printf("Not exist");
        }
        else
        {
            printf("%s", str);
        }
    }
    
    if (command == 'R')
    {
        bool flag = true;
        char secondCommand, thirdCommand;
        scanf(" %c %c", &secondCommand, &thirdCommand);
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == secondCommand)
            {
                str[i] = thirdCommand;
                flag = false;
            }
        }
        
        if (flag)
        {
            printf("Not exist");
        }
        else
        {
            printf("%s", str);
        }
    }
    
    return 0;
}
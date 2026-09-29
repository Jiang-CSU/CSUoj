#include <stdio.h>
#include <string.h>

void reverse(char str[], int length)
{
    for (int i = 0; i <= (length / 2) - 1; i++)
    {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main(void)
{
    char s[2001];
    char t[1001];
    while (scanf("%s", s) == 1)
    {
        scanf("%s", t);
        int lenS = strlen(s);
        int lenT = strlen(t);
        
        reverse(s, lenS);
        reverse(t, lenT);
        
        strcat(s, t);
        printf("%s\n", s);
    }
    return 0;
}
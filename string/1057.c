#include <stdio.h>
#include <string.h>

int main(void)
{
    char S1[10001] = "";
    
    while (fgets(S1, sizeof(S1), stdin) != NULL)
    {
        // S1[strcspn(S1, "\n")] = '\0';
        
        char S2[10001] = "";
        fgets(S2, sizeof(S2), stdin);
            
        int len1 = strlen(S1);
        int len2 = strlen(S2);
        
        for (int i = 0; i < len2; i++)
        {
            for (int j = 0; j < len1; j++)
            {
                if (S1[j] == S2[i])
                {
                    S1[j] = '\0';
                }
            }
        }
        
        char result[10001];
        int index = 0;
        for (int i = 0; i < len1; i++)
        {
            if (S1[i] != '\0')
            {
                result[index++] = S1[i];
            }
        }
        
        result[index] = '\0';
        
        printf("%s\n", result);
    }
    
    return 0;
}
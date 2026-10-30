#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    char name[N][1001];
    char str[M][31];
    int count[N];
    
    for (int i = 0; i < N; i++)
    {
        count[i] = 0;
    }
    
    for (int i = 0; i < N; i++)
    {
        scanf("%s", name[i]);
    }
    
    for (int i = 0; i < M; i++)
    {
        scanf("%s", str[i]);
    }
    
    for (int i = 0; i < N; i++)
    {
        int nameLen = strlen(name[i]);
        
        for (int j = 0; j < M; j++)
        {
            int indexName = 0;
            int indexStr = 0;
            int strLen = strlen(str[j]);
            
            while (indexName < nameLen && indexStr < strLen)
            {
                if (tolower(name[i][indexName]) == tolower(str[j][indexStr]))
                {
                    indexStr++;
                }
                
                indexName++;
            }
            
            if (indexStr == strLen)
            {
                count[i]++;
            }
        }
        
    }
    
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", count[i]);
    }

    return 0;
}
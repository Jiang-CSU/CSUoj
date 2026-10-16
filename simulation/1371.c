#include <stdio.h>
#include <stdbool.h>

int reversed(int M);

int main(void)
{
    int L;
    scanf("%d", &L);
    
    while (L--)
    {
        int M;
        scanf("%d", &M);
        int count = 0;
        
        while (true)
        {
            int rM = reversed(M);
            
            int sum = rM + M;
            count++;
            
            if (sum == reversed(sum))
            {
                printf("%d\n", count);
                break;
            }
            else
            {
                M = sum;
            }
            
            if (count >= 8)
            {
                printf("0\n");
                break;
            }
        }
        
    }
    return 0;
}

int reversed(int M)
{
    int result = 0;
    
    while (M > 0)
    {
        int res = M % 10;
        result = result * 10 + res;
        M = M / 10;
    }
    
    return result;
}




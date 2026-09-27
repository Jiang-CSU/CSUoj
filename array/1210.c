// 埃氏筛处理加枚举
#include <stdio.h>
#include <stdbool.h>

void isPrimeF(bool[], int);

int main(void)
{
    int n;
    int N = 1000000;
    bool isPrime[N + 1];
    isPrimeF(isPrime, N);
    while (scanf("%d", &n) == 1)
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (isPrime[i] && isPrime[n - i])
            {
                printf("%d %d\n", i, n - i);
            }
        }
        printf("\n");
    }
    return 0;
}

void isPrimeF(bool isPrime[], int N)
{
    for (int i = 0; i <= N; i++)
    {
        isPrime[i] = true;
    }
    
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (int j = 2; j * j <= N; j++)
    {
        if (isPrime[j])
        {
            for (int k = j * j; k <= N; k += j)
            {
                isPrime[k] = false;
            }
        }
    }
}


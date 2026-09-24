#include <stdio.h>
#include <stdbool.h>

void isPrimeF(bool[], int);

int main(void)
{
    int n;
    scanf("%d", &n);
    bool isPrime[1000001];
    isPrimeF(isPrime, 1000000);
    
    while (n--)
    {
        int a, b;
        int count = 0;
        
        scanf("%d %d", &a, &b);
        for (int i = a; i <= b; i++) {
            if (isPrime[i])
            {
                count++;
            }
        }
        
        printf("%d\n", count);
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
    
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    
}
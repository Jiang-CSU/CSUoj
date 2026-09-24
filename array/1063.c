#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n + 1];
    long long ans = 0;
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (int i = 1; i <= n; i++) 
    {
    if (a[i] < 0)
        ans += (long long)a[i] * i;
    else
        ans += a[i];
    }
    
    printf("%lld\n", ans);
    return 0;
}
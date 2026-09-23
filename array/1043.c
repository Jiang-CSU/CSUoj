// 经典的动态规划入门题。主要是能想到怎么去转化，以及题目的识别。
#include <stdio.h>

int max(int, int);

int main(void)
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        int amount[n];
        int dp[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &amount[i]);
        }
        
        dp[0] = amount[0];
        dp[1] = max(amount[0], amount[1]);
        for (int j = 2; j < n; j++)
        {
            // 如果不选，dp[j]和dp[j - 1]一样，如果选，那就由dp[j - 2]来延续状态
            dp[j] = max(dp[j - 1], dp[j - 2] + amount[j]);
        }
        
        printf("%d\n", dp[n - 1]);
    }
}

int max(int a, int b)
{
    return (a >= b ? a : b);
}
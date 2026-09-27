// 难点主要在long long以及不可循环叠加（复杂度过高）
#include <stdio.h>

int main(void)
{
    int n, T;
    scanf("%d %d", &n, &T);
    
    long long money[n];
    int moneyOrigin[n];
    scanf("%d", &money[0]);
    moneyOrigin[0] = money[0];
    for (int i = 1; i < n; i++)
    {
        scanf("%lld", &money[i]);
        moneyOrigin[i] = money[i];
        money[i] += money[i - 1];
    }
    
    while (T--)
    {
        int L, R;
        scanf("%d %d", &L, &R);
        
        long long count = money[R - 1] - money[L - 1] + moneyOrigin[L - 1];
        
        printf("%lld\n", count);
    }
    
    return 0;
}


// 标准的下缀和写法，数组的第一位设为0，从第二位才开始读取
#include <stdio.h>

// 1. 全局数组定义：避开栈溢出，且默认全自动初始化为 0
long long money[100005]; 

int main(void)
{
    int n, T;
    if (scanf("%d %d", &n, &T) != 2) return 0;
    
    // 2. 下标从 1 开始存，money[0] 默认为 0
    for (int i = 1; i <= n; i++)
    {
        long long a;
        scanf("%lld", &a);             // %lld 读取 long long
        money[i] = money[i - 1] + a;   // 标准前缀和公式
    }
    
    while (T--)
    {
        int L, R;
        scanf("%d %d", &L, &R);
        
        // 3. 极简公式：不需要 moneyOrigin 数组，也不用防边界
        long long count = money[R] - money[L - 1];
        
        printf("%lld\n", count);        // %lld 输出 long long
    }
    
    return 0;
}
#include <stdio.h>

int main(void) {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        int price[n];

        int maxIndex = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &price[i]);

            if (price[i] > price[maxIndex]) {
                maxIndex = i;
            }
        }

        int m;
        scanf("%d", &m);

        if (m < 5) {
            printf("%d\n", m);
            continue;
        }

        // 把最贵的菜放到最后
        int temp = price[maxIndex];
        price[maxIndex] = price[n - 1];
        price[n - 1] = temp;

        int capacity = m - 5;
        int dp[capacity + 1];

        // 初始化
        for (int j = 0; j <= capacity; j++) {
            dp[j] = 0;
        }

        // 前 n-1 道菜做 0/1 背包，其实本质就是dp问题
        for (int i = 0; i < n - 1; i++) {
            int p = price[i];

            // 注意：必须倒着！如果新方案比原方案耗得钱更多，就采用，否则保持原方案
            for (int j = capacity; j >= p; j--) {
                if (dp[j - p] + p > dp[j]) {
                    dp[j] = dp[j - p] + p;
                }
            }
        }

        printf("%d\n", m - dp[capacity] - price[n - 1]);
    }

    return 0;
}
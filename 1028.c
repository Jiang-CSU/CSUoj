// 依旧自己的方法，但复杂度O(n²)，对于25亿次的计算很容易TLE。时间复杂度降不下去，这是现在很大的问题
// #include <stdio.h>
// #include <stdbool.h>

// int main(void) {
    
//     int T;
//     scanf("%d", &T);
    
//     for (int i = 0; i < T; i++) {
        
//         int N, K;
//         scanf("%d %d", &N, &K);
        
//         int arr[N];
//         for (int j = 0; j < N; j++) {
//             scanf("%d", &arr[j]);
//         }
        
//         int index = 0;
//         bool isUsed[N];
        
//         for (int j = 0; j < N; j++) {
//             isUsed[j] = false;
//         }
//         bool valid = true;
        
//         while (true) {
            
//             while (index < N && isUsed[index]) {
//                 index++;
//             }
            
//             if (index == N) {
//                 break;
//             }
            
//             int curr = arr[index];
//             // bool flag = false;
            
//             for (int k = 0; k < K; k++) {
//                 bool found = false;
//                 for (int j = index; j < N; j++) {
                    
//                     if (!isUsed[j] && arr[j] == curr + k) {
//                         isUsed[j] = true;
//                         found = true;
//                         break;
//                     }
//                 }
                
//                 if (!found) {
//                     valid = false;
//                     break;
//                 }
//             }
            
//             if (!valid) {
//                 break;
//             }
            
//         }
        
//         if (valid) {
//             printf("YES\n");
//         } else {
//             printf("NO\n");
//         }
//     }
// }


// chatgpt给的方法，复杂度直接到O(n)级别
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        int arr[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        // 数量不是 K 的倍数，必然不可能
        if (N % K != 0) {
            printf("NO\n");
            continue;
        }

        // 压缩数组
        // value[i]：第 i 种数字
        // count[i]：这个数字出现多少次
        int value[N];
        int count[N];
        int m = 0;

        // 统计每个数字出现的频率
        for (int i = 0; i < N; i++) {

            if (m == 0 || arr[i] != value[m - 1]) {
                value[m] = arr[i];
                count[m] = 1;
                m++;
            } else {
                count[m - 1]++;
            }
        }

        bool valid = true;

        // 外层i循环找当前剩余的最小的数字
        for (int i = 0; i < m; i++) {

            // 如果该数字没有了，则continue找下一个
            if (count[i] == 0)
                continue; 

            // 当前最小数字还有 num 个
            // 那么必须同时开启 num 个连续组
            int num = count[i];


            // 内层 j：从这个数字开始，连续找 K 个数字，每个数字都拿走 num 个
            for (int j = 0; j < K; j++) {

                // i+j 超出范围
                if (i + j >= m) {
                    valid = false;
                    break;
                }

                // 数字必须连续（如果不连续如12456，想找k = 3的，很明显不行）
                if (value[i + j] != value[i] + j) {
                    valid = false;
                    break;
                }

                // 数量必须足够（不够则说明无法构成耦合数组）
                if (count[i + j] < num) {
                    valid = false;
                    break;
                }

                count[i + j] -= num;
            }

            if (!valid)
                break;
        }

        if (valid)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h> 

// bool isValid(char A[], char B[]);

// int main(void) {
    
//     char A[100001];
//     char B[100001];
//     while (scanf("%s %s", A, B) == 2) {
        
//         if (isValid(A, B)) {
            
//             int lenA = strlen(A);
//             int indexA = 0;
//             int indexB = 0;
            
//             while (true) {
               
//               if (B[indexB] == A[indexA % lenA]) {
//                   indexB++;
//                   indexA++;
//                 } else {
//                   indexA++;
//                 }
               
//               if (B[indexB] == '\0') {
//                   printf("%d\n", ((indexA + lenA) / lenA));
//                   break;
//                 }
                
//             }
//         } else {
//             printf("-1\n");
//         }
        
//     }
// }

// // bool isValid(char A[], char B[]) {
// //     bool flag;
    
// //     for (int i = 0; B[i] != '\0'; i++) {
// //         flag = true;
// //         for (int j = 0; A[j] != '\0'; j++) {
// //             if (B[i] == A[j]) {
// //                 flag = false;
// //                 break;
// //             }
            
// //         }
// //         if (flag) {
// //             return false;
// //         }
// //     }
    
// //     return true;
// // }

// bool isValid(char A[], char B[]) {
    
//     bool exist[26] = {false};
    
//     for (int i = 0; A[i] != '\0'; i++) {
//         exist[A[i] - 'a'] = true;
//     }
    
//     for (int j = 0; B[j] != '\0'; j++) {
//         if (exist[B[j] - 'a'] == false) {
//             return false;
//         }
//     }
    
//     return true;
// }



#include <stdio.h>
#include <string.h>

#define MAXN 100005

char A[MAXN];
char B[MAXN];

/*
nextPos[i][c]:
从 A 的下标 i 开始往右，
字符 c 下一次出现的位置。

如果不存在，就是 -1。
*/
int nextPos[MAXN][26];

int main(void) {

    while (scanf("%100000s %100000s", A, B) == 2) {

        int lenA = strlen(A);
        int lenB = strlen(B);

        // -------------------------
        // 1. 预处理 nextPos
        // -------------------------

        for (int c = 0; c < 26; c++) {
            nextPos[lenA][c] = -1;
        }

        for (int i = lenA - 1; i >= 0; i--) {

            // 先继承 i+1 位置的信息
            for (int c = 0; c < 26; c++) {
                nextPos[i][c] = nextPos[i + 1][c];
            }

            // A[i] 这个字符就在当前位置
            nextPos[i][A[i] - 'a'] = i;
        }

        // -------------------------
        // 2. 匹配 B
        // -------------------------

        int pos = 0;      // 当前在这一份 A 中的位置
        int count = 1;    // 当前使用了几份 A
        int possible = 1;

        for (int i = 0; i < lenB; i++) {

            int c = B[i] - 'a';

            // 从当前位置往后能找到 B[i]
            if (nextPos[pos][c] != -1) {

                pos = nextPos[pos][c] + 1;

                // 如果刚好走到 A 末尾
                if (pos == lenA) {
                    pos = 0;

                    // B 还有字符，才需要下一份 A
                    if (i != lenB - 1) {
                        count++;
                    }
                }

            } else {

                // 整个 A 都没有这个字符
                if (nextPos[0][c] == -1) {
                    possible = 0;
                    break;
                }

                // 当前这一份剩下的位置没有，
                // 去下一份 A
                count++;

                pos = nextPos[0][c] + 1;

                if (pos == lenA) {
                    pos = 0;

                    if (i != lenB - 1) {
                        count++;
                    }
                }
            }
        }

        if (possible) {
            printf("%d\n", count);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}

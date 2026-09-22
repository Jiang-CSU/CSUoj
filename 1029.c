// 自己的方法，实际是模拟了一个栈。我没想到用栈的话如何避免index乱的问题，所以使用该种方法。坏处是复杂度上升到了O(n²)
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    
    char str[100001];
    while (scanf("%s", str) == 1) {
                
        int index = 1;
        int count[100000] = {0};
        for (int i = 0; str[i] != '\0'; i++) {
            
            if (str[i] == '(') {
                index++;
            } else {
                int curr = index;
                
                while (true) {
                    
                    curr--;
                    if (count[curr] == 0) {
                        count[curr] = index;
                        count[index] = -1;
                        break;
                    }
                    
                }
                index++;
            }
        }
        
        for (int j = 0; j < index; j++) {
            if (count[j] != 0 && count[j] != -1) {
                printf("%d %d\n", j, count[j]);
            }
        }
    }
}


// -------------------------------------------------------------------------



// chatgpt给出的标准栈写法。注意压栈只是将对应的index压进去，否则不好统计对应括号的index
#include <stdio.h>

int main(void) {
    char str[100001];

    while (scanf("%100000s", str) == 1) {

        int stack[100000];
        int match[100001] = {0};
        int top = -1;

        // 遍历字符串
        for (int i = 0; str[i] != '\0'; i++) {

            if (str[i] == '(') {
                // 左括号的位置入栈
                stack[++top] = i + 1;
            }

            else if (str[i] == ')') {
                // 最近的未匹配左括号出栈
                int left = stack[top--];
                int right = i + 1;

                match[left] = right;
            }
        }

        // 按左括号的位置从小到大输出
        for (int i = 1; str[i - 1] != '\0'; i++) {
            if (match[i] != 0) {
                printf("%d %d\n", i, match[i]);
            }
        }
    }

    return 0;
}
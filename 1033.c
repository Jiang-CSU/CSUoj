#include <stdio.h>
#include <string.h>

int main(void) {
    
    int n;
    scanf("%d", &n);
    
    while (n--) {
        
        int m;
        scanf("%d", &m);
        int constantM = m;
        int count = 0;
        int step[constantM];
        
        while (m--) {
            
            char str[6];
            scanf("%s", str);
            
            if (strcmp(str, "LEFT") == 0) {
                count--;
                step[constantM - m - 1] = -1;
            } else if (strcmp(str, "RIGHT") == 0) {
                count++;
                step[constantM - m - 1] = 1;
            } else {
                char as[3];
                int number;
                scanf("%s %d", as, &number);
                
                if (step[number - 1] == 1) {
                    count++;
                    step[constantM - m - 1] = 1;
                } else {
                    count--;
                    step[constantM - m - 1] = -1;
                }
            }
            
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}
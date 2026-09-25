#include <stdio.h>

int main(void) {
    
    int n;
    while (scanf("%d", &n) == 1)
    {
        int temp = 0;
        int reverse = 0;

        while (n != 0)
        {
            int rem = n % 10;
            reverse = temp * 10 + rem;
            temp = reverse;
            n = n / 10;
        }
        
        printf("%d\n", reverse);
    }
    
    return 0;
}
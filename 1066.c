#include <stdio.h>

int main(void)
{
    int n;
    char c;
    
    int arr[1000] = {0};
    arr[1] = 1;
    
    for (int i = 2; i < 1000; i++)
    {
        arr[i] = arr[i - 1] + 6 + (4 * (i - 2)); 
    }
    // 1 7 17 31 49
    
    while (scanf("%d %c", &n, &c) == 2)
    {
        int index;
        
        for (int i = 1; i < 1000; i++)
        {
            if (n < arr[i])
            {
                index = i - 1;
                break;
            }
        }
        
        for (int i = index; i > 0; i--)
        {
            for (int k = i; k < index; k++)
            {
                printf(" ");
            }
            
            for (int j = i * 2 - 1; j > 0; j--)
            {
                printf("%c", c);
            }
            printf("\n");
        }
        
        for (int i = 2; i <= index; i++)
        {
            for (int k = i; k < index; k++)
            {
                printf(" ");
            }
            
            for (int j = 0; j < i * 2 - 1; j++)
            {
                printf("%c", c);
            }
            printf("\n");
        }
        
        printf("%d\n", n - arr[index]);
        
    }
    return 0;
}
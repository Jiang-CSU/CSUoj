#include <stdio.h>

int main(void)
{
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    int arr[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int line = n / m + 1;
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        if ((i + 1) % m == 0 && i != 0 && i != n - 1)
        {
            printf("\n");
        }
    }
    printf("\n");
    
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    
    double average = total / n;
    
    int max = 0, min = arr[0];
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    
    printf("max:%d\n", max);
    printf("min:%d\n", min);
    printf("average:%.6f\n", average);
    
    return 0;
}
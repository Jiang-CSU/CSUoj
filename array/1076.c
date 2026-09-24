#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int count[101] = {0};
    int age;
    
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &age);
        count[age]++;
    }
    
    for (int j = 1; j <= 100; j++)
    {
        while (count[j]--)
        {
            printf("%d ", j);
        }
    }
    
    return 0;

}
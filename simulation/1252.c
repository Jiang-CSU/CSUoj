// 处理第一位数字的方法，取log10。这个方法以前没有接触过，更多的是数学思想
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    double x = (double)n * log10(n);
    double fractional = x - floor(x);

    int result = (int)pow(10.0, fractional);

    printf("%d\n", result);

    return 0;
}
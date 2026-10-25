#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int min(int a, int b)
{
    return a < b ? a : b; 
}

int main(void)
{
    int N, M, p;
    
    scanf("%d %d %d", &N, &M, &p);
    
    int stop[M + 1];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &stop[i]);
    }
    
    stop[M] = p;
    
    qsort(stop, M + 1, sizeof(int), cmp);
    
    int minResult = N;
    for (int i = 0; i < M + 1; i++)
    {
        int g, length1, length2;

        if (i == M)
        {
            g = N - (stop[i] - stop[0]);

            length1 = p - stop[0];
            length2 = stop[M] - p;
        }
        else
        {
            g = stop[i + 1] - stop[i];

            if (stop[i + 1] <= p)
            {
                length1 = N - (p - stop[i]);
                length2 = p - stop[i + 1];
            }
            else
            {
                length1 = stop[i] - p;
                length2 = N - (stop[i + 1] - p);
            }
        }

        int result = N - g + min(length1, length2);

        if (result < minResult)
        {
            minResult = result;
        }
    }
    
    printf("%d", minResult * 100);
    
    return 0;
}




/********************
 作者：蒋书涵
 提交时间：2026-10-25 17:30:16
 内存：2260kb
 耗时：119ms
 结果：正确 AC:100.00%
********************/
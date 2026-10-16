#include <stdio.h>
#include <stdbool.h>

int gcd(int m, int d);
int lcm(int m, int d);

int main(void)
{
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        
        int mm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // 不需要额外考虑闰年。。。hh
        // int mm29[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int count = 0;
        int month;
        int date;
        
        for (int i = 1; i < 13; i++)
        {
            for (int j = 1; j <= mm[i - 1]; j++)
            {
                if (gcd(i, j) == x && lcm(i, j) == y)
                {
                    month = i;
                    date = j;
                    count++;
                }
            }
        }
        
        if (count == 0)
        {
            printf("Case #%d: -1\n", i + 1);
        }
        else if (count == 1)
        {
            printf("Case #%d: %d/%02d/%02d\n", i + 1, z, month, date);
        }
        else
        {
            printf("Case #%d: 1\n", i + 1);
        }
        
    }
    
    return 0;
}

int gcd(int m, int d)
{
    int min = m > d ? d : m;
    
    for (int i = min; i > 0; i--)
    {
        if (m % i == 0 && d % i == 0)
        {
            return i;
        }
    }
}

int lcm(int m, int d)
{
    int max = m > d ? m : d;
    
    int temp = max;
    
    while (true)
    {
        if (temp % m == 0 && temp % d == 0)
        {
            return temp;
        }
        temp += max;
    }
}
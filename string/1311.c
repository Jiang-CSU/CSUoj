// 1 2 3
// 4 5 6
// 7 8 9

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(int first, int second, bool isUsed[][3], int x[], int y[]);

int main(void)
{
    int T;
    scanf("%d", &T);
    int y[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    int x[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    
    while (T--)
    {
        char key[10];
        scanf("%s", key);
        int length = strlen(key);
        bool isUsed[3][3] = {false};
        bool flag = true;
        
        for (int i = 0; i < length - 1; i++)
        {
            int first = key[i] - '0';
            int second = key[i + 1] - '0';
            
            if (isValid(first, second, isUsed, x, y))
            {
                isUsed[x[first - 1]][y[first - 1]] = true;
            }
            else
            {
                printf("No\n");
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            printf("Yes\n");
        }

    }
    
    return 0;
}

bool isValid(int first, int second, bool isUsed[][3], int x[], int y[])
{
    int dis = abs(x[first - 1] - x[second - 1]) + abs(y[first - 1] - y[second - 1]);
    
    if (dis == 1)
    {
        return true;
    }
    else if (dis == 2 && x[first - 1] != x[second - 1] && y[first - 1] != y[second - 1])
    {
        return true;
    }
    else if (dis == 2 && y[first - 1] == y[second - 1])
    {
        if (isUsed[x[(first + second) / 2 - 1]][y[(first + second) / 2 - 1]])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (dis == 2 && x[first - 1] == x[second - 1])
    {
        if (isUsed[x[(first + second) / 2 - 1]][y[(first + second) / 2 - 1]])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (dis == 3)
    {
        return true;
    }
    else
    {
        if (isUsed[1][1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
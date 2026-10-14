#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n, m, t;
    
    while (scanf("%d %d %d", &n, &m, &t) == 3)
    {
        if (n == 0)
        {
            break;
        }
        
        char matrix[n][m];
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf(" %c", &matrix[i][j]);
            }
        }
        
        int x = 0;
        int y = t - 1;
        int count = 0;
        
        int recordX[100];
        int recordY[100];
        bool flag = true;
        
        while ((x >= 0 && x < n) && (y >= 0 && y < m))
        {
            recordX[count] = x;
            recordY[count] = y;
            
            if (matrix[x][y] == 'N')
            {
                x--;
            }
            else if (matrix[x][y] == 'S')
            {
                x++;
            }
            else if (matrix[x][y] == 'W')
            {
                y--;
            }
            else
            {
                y++;
            }
            
            for (int i = 0; i < count; i++)
            {
                if (x == recordX[i] && y == recordY[i])
                {
                    printf("%d step(s) before a loop of %d step(s)\n", i, count - i + 1);
                    flag = false;
                    break;
                }
            }
            
            if (!flag)
            {
                break;
            }
            
            count++;
        }
        
        if (flag)
        {
            printf("%d step(s) to exit\n", count);
        }
    }
}
#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    bool isFirstRowZero = false;
    bool isFirstColZero = false;
    
    int matrix[m][n];
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && matrix[i][j] == 0)
            {
                isFirstRowZero = true;
            }
            
            if (j == 0 && matrix[i][j] == 0)
            {
                isFirstColZero = true;
            }
            
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    
    if (isFirstColZero)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
    
    if (isFirstRowZero)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                printf("%d\n", matrix[i][j]);
            }
            else
            {
                printf("%d ", matrix[i][j]);
            }
        }    
    }        
    
    return 0;
}
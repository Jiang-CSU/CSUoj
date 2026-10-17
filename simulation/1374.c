#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    
    while (N--)
    {
        char pos[3];
        
        scanf("%s", pos);
        
        int arr1[] = {1, -1};
        int arr2[] = {2, -2};
        int count = 0;
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int x1 = (pos[0] - 'a' + 1) + arr1[i];
                int y1 = (pos[1] - '0') + arr2[j];
                if (x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8)
                {
                    count++;
                }
                
                int x2 = (pos[0] - 'a' + 1) + arr2[j];
                int y2 = (pos[1] - '0') + arr1[i];
                if (x2 >= 1 && x2 <= 8 && y2 >= 1 && y2 <= 8)
                {
                    count++;
                }
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int h1;
    
    while (true)
    {
        scanf("%d", &h1);
        
        if (h1 == 0)
        {
            break;
        }
        
        int h[5];
        h[0] = h1;
        
        for (int i = 1; i < 5; i++)
        {
            scanf("%d", &h[i]);
        }
        
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;
        
        for (int i = 0; i < 5; i++)
        {
            if (h[i] == 1)
            {
                flag1 = true;
            }
            else if (h[i] == 2)
            {
                flag2 = true;
            }
            else
            {
                flag3 = true;
            }
        }
        
        if ((flag1 && flag2 && flag3) || (flag1 && !flag2 && !flag3) || (!flag1 && flag2 && !flag3) || (!flag1 && !flag2 && flag3))
        {
            for (int i = 0; i < 5; i++)
            {
                printf("3\n");
            }
        }
        else if (flag1 && flag2)
        {
            for (int i = 0; i < 5; i++)
            {
                if (h[i] == 1)
                {
                    printf("1\n");
                }
                else
                {
                    printf("2\n");
                }
            }
        }
        else if (flag1 && flag3)
        {
            for (int i = 0; i < 5; i++)
            {
                if (h[i] == 1)
                {
                    printf("2\n");
                }
                else
                {
                    printf("1\n");
                }
            }
        }
        else if (flag2 && flag3)
        {
            for (int i = 0; i < 5; i++)
            {
                if (h[i] == 2)
                {
                    printf("1\n");
                }
                else
                {
                    printf("2\n");
                }
            }
        }
    }
    
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int m;
    while (scanf("%d", &m) == 1)
    {
        char command[5];
        double number;
        int countTurn = 0;
        double x = 0, y = 0;
        
        while (m--)
        {
            scanf("%s", command);
            if (strcmp(command, "TURN") == 0)
            {
                countTurn += 1;
            }
            else
            {
                scanf("%lf", &number);
                if (countTurn % 4 == 1)
                {
                    x += number;
                }
                else if (countTurn % 4 == 2)
                {
                    y -= number;
                }
                else if (countTurn % 4 == 3)
                {
                    x -= number;
                }
                else
                {
                    y += number;
                }
            }
        }
        
        printf("%.3f %.3f\n", x, y);
    }
    return 0;
}
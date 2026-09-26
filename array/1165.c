#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int totalPrize = 0;
    int maxPrize = 0;
    char maxPrizeName[21];
    
    for (int i = 0; i < n; i++)
    {
        char name[21];
        int finalScore;
        int classScore;
        char cadre;
        char west;
        int essay;
        int total = 0;
        
        scanf("%s", name);
        scanf("%d", &finalScore);
        scanf("%d", &classScore);
        scanf(" %c", &cadre);
        scanf(" %c", &west);
        scanf("%d", &essay);
        
        if (finalScore > 80 && essay > 0)
        {
            total += 8000;
        }
        
        if (finalScore > 85 && classScore > 80)
        {
            total += 4000;
        }
        
        if (finalScore > 90)
        {
            total += 2000;
        }
        
        if (finalScore > 85 && west == 'Y')
        {
            total += 1000;
        }
        
        if (classScore > 80 && cadre == 'Y')
        {
            total += 850;
        }
        
        totalPrize += total;
        
        if (total > maxPrize)
        {
            maxPrize = total;
            strcpy(maxPrizeName, name);
        }
    }
    
    printf("%s\n", maxPrizeName);
    printf("%d\n", maxPrize);
    printf("%d", totalPrize);
    
    return 0;
}
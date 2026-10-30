// 细节处理是这个题导致WA的关键。end % 2 ==0 以及end > 0都是关键点，前者处理奇数问题，后者是防止while循环进入死循环（当end为1的时候再除2得到0）
// 简单题算法、实现不成问题，但边界、条件处理才能成功AC
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isReversed(char str[], int end);

int main(void)
{
    char str[1000];
    
    scanf("%s", str);
    
    int end = strlen(str);
    while (end % 2 == 0 && end > 0 && isReversed(str, end))
    {
        end /= 2;
    }
    
    printf("%d", end);
    return 0;
}

bool isReversed(char str[], int end)
{
    for (int i = 0, j = end - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }
    
    return true;
}

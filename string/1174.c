#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[11];
    scanf("%s", arr);
    
    int length = strlen(arr);
    
    char rev_arr[11] = {0};
    for (int i = length - 1; i >= 0; i--)
    {
        rev_arr[length - 1 - i] = arr[i];
    }
    
    if (strcmp(rev_arr, arr) == 0)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int h;
    int m;
} Bus;

int main(void)
{
    int N, M;
    
    scanf("%d", &N);
    Bus *list = (Bus*) malloc(N * sizeof(Bus));
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &list[i].h);
        scanf("%d", &list[i].m);
    }
    
    scanf("%d", &M);
    int length = N + M;
    Bus *temp_list = (Bus*) realloc(list, length * sizeof(Bus));
    
    if (temp_list != NULL) {
        list = temp_list;
    }
    
    for (int i = N; i < length; i++)
    {
        scanf("%d", &list[i].h);
        scanf("%d", &list[i].m);
    }
    
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if ((list[j].h > list[j + 1].h) || 
            ((list[j].h == list[j + 1].h) && (list[j].m > list[j + 1].m)))
            {
                Bus temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < length; i++)
    {
        bool flag = false;
        
        for (int j = 0; j < i; j++)
        {
            if (list[i].h == list[j].h && list[i].m == list[j].m)
            {
                flag = true;
                break;
            }
        }
        
        if (flag)
        {
            continue;
        }
        else
        {
            printf("%d:%02d ", list[i].h, list[i].m);
        }
    }
    
    return 0;
}

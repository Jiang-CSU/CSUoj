#include <stdio.h>
#include <stdbool.h>

bool isFull(int product, int number);

int main(void)
{
    int n;
    int loopIndex = 0;
    
    while (++loopIndex > 0)
    {
        scanf("%d", &n);
        
        if (n == 0)
        {
            break;
        }
        
        if (loopIndex != 1)
        {
            printf("\n");
        }
        
        bool flag = true;
        
        for (int i = 1000; i < 9999; i++)
        {
            int product = n * i;
            
            if (product <= 10000)
            {
                continue;
            }
            if (product >= 100000)
            {
                break;
            }
            
            if (isFull(product, i * 10))
            {
                printf("%d / 0%d = %d\n", product, i, n);
                flag = false;
            }
        }
        
        if (n <= 9)
        {
            for (int i = 10000; i < 99999; i++)
            {
                int product = n * i;
                if (product >= 100000)
                {
                    break;
                }
                
                if (isFull(product, i))
                {
                    printf("%d / %d = %d\n", product, i, n);
                    flag = false;
                }
            }
        }
        
        if (flag)
        {
            printf("There are no solutions for %d.\n", n);
        }
        
        

    }
}

bool isFull(int product, int number)
{
    int arr[10];
    int index = 0;
    
    while (number > 0)
    {
        int rem = number % 10;
        
        for (int i = 0; i < index; i++)
        {
            if (rem == arr[i])
            {
                return false;
            }
        }
        
        arr[index++] = rem;
        number /= 10;
    }
    
    while (product > 0)
    {
        int rem = product % 10;
        
        for (int i = 0; i < index; i++)
        {
            if (rem == arr[i])
            {
                return false;
            }
        }
        
        arr[index++] = rem;
        product /= 10;
    }
    
    return true;
}

// bool isDifferent(int number, int length)
// {
//     int arr[length];
//     int index = 0;
    
//     while (number > 0)
//     {
//         int rem = number % 10;
        
//         for (int i = 0; i < index; i++)
//         {
//             if (rem == arr[i])
//             {
//                 return false;
//             }
//         }
        
//         arr[index++] = rem;
//         number /= 10;
//     }
    
//     return true;
// }
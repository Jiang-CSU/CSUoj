#include <stdio.h>
#include <string.h>

int array_gcd(int arr[], int n);
int gcd(int a, int b);

typedef struct{
    char value;
    int number;
} Letter;

int main(void)
{
    char str[1000];
    while (scanf("%s", str) != EOF)
    {
        char option[3];
        scanf("%s", option);
        
        int count[26] = {0};
        int total = 0;
        int maxCount = 0;
        
        for (int i = 0; str[i] != '\0'; i++)
        {  
            count[str[i] - 'a']++;
        }
        
        int gcd = array_gcd(count, 26);
        
        for (int i = 0; i < 26; i++)
        {
            count[i] /= gcd;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                total++;
            }
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > maxCount)
            {
                maxCount = count[i];
            }
        }
        
        Letter result[total];
        int index = 0;
        
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                result[index].value = i + 'a';
                result[index].number = count[i];
                index++;
            }
        }
        
        char matrix[maxCount + 1][total];
        memset(matrix, ' ', sizeof(matrix));
        
        if (strcmp(option, "P1") == 0)
        {
            for (int i = 0; i < total; i++)
            {
                matrix[maxCount][i] = result[i].value;
            }
            
            for (int i = 0; i < total; i++)
            {
                for (int j = 0; j < result[i].number; j++)
                {
                    matrix[maxCount - 1 - j][i] = '*';
                }
            }
        }
        else
        {
            for (int i = 0; i < total - 1; i++)
            {
                for (int j = i + 1; j < total; j++)
                {
                    if (result[i].number < result[j].number ||
                        (result[i].number == result[j].number &&
                        result[i].value > result[j].value))
                    {
                        Letter temp = result[i];
                        result[i] = result[j];
                        result[j] = temp;
                    }
                }
            }
            
            for (int i = 0; i < total; i++)
            {
                matrix[maxCount][i] = result[i].value;
            }
            
            for (int i = 0; i < total; i++)
            {
                for (int j = 0; j < result[i].number; j++)
                {
                    matrix[maxCount - 1 - j][i] = '*';
                }
            }
        }
        
        for (int i = 0; i < maxCount + 1; i++)
        {
            for (int j = 0; j < total; j++)
            {
                if (j != total - 1)
                {
                    printf("%c", matrix[i][j]);
                }
                else
                {
                    printf("%c\n", matrix[i][j]);
                }
                
            }
        }
        
        printf("\n");
    }
    
    return 0;
}

int array_gcd(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(result, arr[i]);
        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

int gcd(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
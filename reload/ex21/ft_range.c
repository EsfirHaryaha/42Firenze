#include <stdio.h>
#include <stdlib.h>
int *ft_range(int min, int max);

int *ft_range(int min, int max)
{
    int len;
    int *array;

    len = max - min;
    if(min >= max)
        return (NULL);
    array = malloc(sizeof(int) * len);
    while(len > 0)
    {
        array[len - 1] = max--;
        len--;
    }
    return (array);
}

int main(void)
{
    int a = 8;
    int b = 5;
    int *array = ft_range(a, b);
    if (!array)
    {
        printf("NULL\n");
        return (0);
    }
    int len = b - a;
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");
    free(array);
    return (0);
}
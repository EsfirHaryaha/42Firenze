#include <stdio.h>
int ft_sqrt(int nb);

int ft_sqrt(int nb)
{
    int i;

    i = 0;
    while (i * i <= nb)
    {
        if (i * i == nb)
        {
            return (i);
        }
        i++;
    }
    return (0);
}

int main(void)
{
    int nb = 20;
    printf("%d  -->  %d\n", nb, ft_sqrt(nb));
    return (0);
}
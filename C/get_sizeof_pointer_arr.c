#include <stdio.h>

void f(int *abc)
{
    printf("abc size : %d\n", sizeof(*abc) / sizeof(char));
    // abc size : 4

    size_t i = 1;
    for (; *abc; abc++, i++)
        printf("%d ", *abc);
    abc -= i;
    printf("\nsize : %d\n", i);
    // 1 2 3 4 5
    // size: 6
}

int main(int ac, char const *av[])
{
    int b[] = {1, 2, 3, 4, 5, 0};
    f(b);
}
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, *p_a;
    float b, *p_b;
    p_a = (int *)malloc(sizeof(int));
    p_b = (float *)malloc(sizeof(float));
    *p_a = 10;
    *p_b = 3.14;
    printf("a is %d, b is %f \n ", *p_a, *p_b);
    free(p_a);
    free(p_b);
    return 0;
}
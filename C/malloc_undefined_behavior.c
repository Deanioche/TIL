#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *p, *pp, *ppp;

    p = (char *)malloc(3);
    pp = (char *)malloc(3);
    ppp = (char *)malloc(3);

    printf("in p : ");
    scanf("%s", p);

    printf("\nin pp : ");
    scanf("%s", pp);

    printf("\nin ppp : ");
    scanf("%s", ppp);

    printf("\np : %s", p);
    printf("\npp : %s", pp);
    printf("\npp : %s", ppp);

    printf("\np : %d", &p);
    printf("\npp : %d", &pp);
    printf("\npp : %d", &ppp);

    return 0;
}

// 실행 결과
/*
Active code page: 65001
in p : 12345678901234567890

in pp : 12345678901234567890

in ppp : 12345678901234567890

p : 1234567890123456123456789012345612345678901234567890
pp : 123456789012345612345678901234567890
pp : 12345678901234567890
p : 6422300
pp : 6422296
pp : 6422292
*/
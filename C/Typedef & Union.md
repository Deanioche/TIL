# Typedef & Union

### # typedef

```c
typedef unsigned int BYTE; 
BYTE val; // 컴파일러가 unsigned int val로 해석

typedef int* Number; // int 포인터를 Number로 지정

typedef struct data DATA; // 구조체 data를 DATA로

typedef struct abc
{
    int x;
    int y;
} ABC; // 구조체 abc를 선언함과 동시에 ABC로 typedef
```

### # union
```c
// 공용체의 멤버가 완전히 다른 자료형을 가질때 기억공간을 절약하기 위해 사용

//숫자를 입력받을 때 정수형, 실수형 자료형이 같이 들어오는 경우
// 메모리의 자료형을 선택해서 값을 저장 가능

union var
{
    int a;
    double b;
    char c;
};

#include <stdio.h>
int main(int argc, char const *argv[])
{
    union var abc; // 공용체 변수 선언

    abc.a = 123;
    abc.b = 12.34;
    abc.c = 'A';

    return 0;
}
```
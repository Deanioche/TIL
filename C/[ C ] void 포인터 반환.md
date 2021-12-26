# **[ C ] void 포인터 반환**

### [**# ref1_void 포인터 반환하기**](https://dojang.io/mod/page/view.php?id=530)

- void *타입에는 메모리의 포인터주소를 담을 수 있다.
    ```c
    void *allocMemory()    // void 포인터를 반환하는 allocMemory 함수 정의
    {
        void *ptr = malloc(100);    // 100바이트만큼 동적 메모리 할당

        return ptr;    // void 포인터 반환
    }
    ```
    또는
    ```c
    void *allocMemory()
    {
        return malloc(100);    // malloc 함수를 호출하면서 바로 반환
    }
    ```
- void 포인터는 다른 타입의 포인터로 자동 변환된다.
    ```c
    char *s1 = allocMemory();       // void 포인터를 char 포인터에 넣어서 문자열처럼 사용
    strcpy(s1, "Hello, world!");    // s1에 Hello, world! 복사
    printf("%s\n", s1);             // Hello, world!
    free(s1);                       // 동적 메모리 해제
    ```
    ```c
    int *numPtr1 = allocMemory();    // void 포인터를 int 포인터에 넣어서 정수 배열처럼 사용
    numPtr1[0] = 10;                 // 첫 번째 요소에 10 저장
    numPtr1[1] = 20;                 // 두 번째 요소에 20 저장
    printf("%d %d\n", numPtr1[0], numPtr1[1]);    // 10 20
    free(numPtr1);                   // 동적 메모리 해제
    ```
### [**# ref2_void 형 함수의 반환 값은 사용을 못하는가?**](https://m.blog.naver.com/tipsware/221291750140)

- void 반환형 값 사용하기
    ```c
    #include <stdio.h>

    void Sum(int a, int b)
    {
        return a + b;   // 경고 발생!!
    }

    int main()
    {
        int s;

        int(*p_sum)(int, int) = (int(*)(int, int))Sum;
        s = (*p_sum)(2, 3);

        printf("s = %d\n", s);
        return 0;
    }
    ```
    - 컴파일은 되지만 **경고 발생**.

### [**함수 포인터를 void*로 선언**](https://blog.naver.com/tipsware/221286469686)

```c
#include <stdio.h>                        

void PrintValue(int a_value)
{
    printf("Value = %d\n", a_value);
}

int main()
{
    void *p_func;
    p_func = PrintValue;  // PrintValue 함수의 주소를 p_func 포인터에 저장!

    // void *에 ((void (*)(int)) 형 변환을 사용하여 PrintValue 함수를 호출!
    (*(void (*)(int))p_func)(5);
    return 0;
}
```

```c
#include <stdio.h>                        

// void PrintValue(int); 형식의 함수 원형을 사용하는
// 함수 포인터 자료형을 PV라고 선언한다.
typedef void(*PV)(int);

void PrintValue(int a_value)
{
    printf("Value = %d\n", a_value);
}

int main()
{
    void *p_func;
    p_func = PrintValue;   // PrintValue 함수의 주소를 p_func 포인터에 저장!

    // void *를 PV 자료형으로 형 변환해서 PrintValue 함수를 호출!
    (*(PV)p_func)(5);
    return 0;
}
```
## **functions**

___

## **#include <string.h>**
문자열 관련 함수들

- ### **strcmp(a, b)** [ref link](https://dojang.io/mod/page/view.php?id=346)

    - 문자열 a와 b가 같은지 비교
    - 같으면 **0** 출력.  
    - 예문
        ```c
        if (!strcmp(s1.name, s2.name))
        {
            printf("동일.");
        }
        ```
        
- ### **strstr(a, b)**
    - 문자열 a에 b가 포함되어있는지 확인
    - 포함되어있으면 true 반환

- ### **strcpy(a, b)**
    - 문자열 a에 b를 입력.
    - JS에서 a = b와 동일. (a, b 는 문자열)

___

## **#include <stdlib.h>**
기본 라이브러리 함수

- ### **rand()**
    - 10자리의 난수 생성

- ### **malloc()**
    - 동적 메모리 할당 함수


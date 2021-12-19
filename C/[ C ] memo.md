# **C - memo**

## 아카이브(archive) 파일 안 들여다보기

https://nomad-programmer.tistory.com/104

- 터미널에서 "nm libft.a" 실행하면
```
ft_strncmp.o:
00000000 b .bss
00000000 d .data
00000000 r .eh_frame
00000000 r .rdata$zzz
00000000 t .text
00000000 T _ft_strncmp

ft_strnstr.o:
00000000 b .bss
00000000 d .data
00000000 r .eh_frame
00000000 r .rdata$zzz
00000000 t .text
         U _ft_memcmp
         U _ft_strlen
00000000 T _ft_strnstr

ft_strrchr.o:
00000000 b .bss
00000000 d .data
00000000 r .eh_frame
00000000 r .rdata$zzz
00000000 t .text
00000000 T _ft_strrchr

ft_strtrim.o:
00000000 b .bss
00000000 d .data
00000000 r .eh_frame
00000000 r .rdata$zzz
00000000 t .text
         U _ft_strchr
         U _ft_strdup
         U _ft_strlcpy
         U _ft_strlen
00000000 T _ft_strtrim
         U _malloc

ft_substr.o:
00000000 b .bss
00000000 d .data
00000000 r .eh_frame
00000000 r .rdata
00000000 r .rdata$zzz
00000000 t .text
         U _ft_strdup
         U _ft_strlcpy
         U _ft_strlen
00000000 T _ft_substr
         U _malloc

```
___

## 배열 n으로 채우기 (memset())
```cpp
#include <stdio.h>
#include <string.h>

int main()
{
    char a[10] = "star";
    memset(a, '*', 10);

    printf("%d %c\n", a[0], a[0]); // 42 *
    printf("%d %c\n", a[1], a[1]); // 42 *
    printf("%d %c\n", a[2], a[2]); // 42 *
    printf("%d %c\n", a[3], a[3]); // 42 *
    printf("%d %c\n", a[4], a[4]); // 42 *
    printf("%d %c\n", a[5], a[5]); // 42 *
    printf("%d %c\n", a[6], a[6]); // 42 *
    printf("%d %c\n", a[7], a[7]); // 42 *
    printf("%d %c\n", a[8], a[8]); // 42 *
    printf("%d %c\n", a[9], a[9]); // 42 *
}
```

___

## 배열 모두 0으로 초기화

[ref link](https://m.blog.naver.com/tipsware/221315173287)

배열을 그냥 빈값으로 초기화하면 쓰레기 값이 들어가므로 모두 0으로 초기화하고 싶다면 다음과 같이 한다.
```cpp
int main()
{
    int a[10] = { 0, };

    printf("%d", a[0]);
    printf("%d", a[1]);
    printf("%d", a[2]);
    printf("%d", a[3]);
    printf("%d", a[4]);
    printf("%d", a[5]);
    printf("%d", a[6]);
    printf("%d", a[7]);
    printf("%d", a[8]);
    printf("%d", a[9]);
}
```
```
000000000
```
___

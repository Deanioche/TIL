## **size_t란?**

### [# ref](https://www.notion.so/size_t-405b810d81b8452ea6f9b1282d816ba4)

- ft_strlen가 반환하는 size_t 자료형
- stdio.h의 소스파일들을 뜯어보다보면 보인다.

- size_t의 t는 typedef
- 플랫폼에 따라 다른 자료형을 쓰기 위해

- 주로 어떤 배열의 length를 구하거나 index를 이용해서 배열에 접근할때 많이 사용을 한다.

- 반복문에서도 count로 음수를 사용하지 않기 때문에 size_t 사용할 수 있다.

## **size_t의 자료형의 크기**

- 64bit os환경에서 64bit로 컴파일 됨.
- unsigned long long 또는 unsigned long int이 된다.

- unsigned long int  라는 자료형은 보통의 컴파일러는 64bit로 컴파일 하기 때문에, word 크기와 같아서 속도가 가장 빠르다고 추론할 수 있다.

- 부호있는 정수형을 사용해야 한다면 부호있는 정수형을 사용하는게 맞고, 만약 **부호를 사용하지 않는 정수형**을 사용해야 한다면 size_t를 사용
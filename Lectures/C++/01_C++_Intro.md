# **C++ 소개**

C++ 프로그램의 기본적인 구조와 선행처리, 명칭공간 등 C++ 언어로 프로그램을 작성하는 기초적인 요소를 학습.

## **학습목표**
선행처리, 문장, 함수 등 C++ 언어의 기본 요소들로 구성된 최소한의 프로그램을 작성할 수 있다.

통합개발환경을 통해 프로그램을 작성하고 빌드하여 실행 프로그램을 만들 수 있다.

___

**firstStep.cpp**  
```cpp
#include <iostream>
int main()
{
    // 표준 출력 스트림으로 문장을 출력함
    std::cout << "나의 첫 번째 C++ 프로그램"
              << std::endl;
    return 0;
}
```

**선행처리의 지시**
```cpp
#include <iostream> // <-- 선행처리기 지시어
int main()
{
// 표준 출력 스트림으로 문장을 출력함
std::cout << "나의 첫 번째 C++ 프로그램"
          << std::endl;
return 0;
}
```

**선행처리란?**

- C++ 프로그램을 컴파일하기 전에 **소스 프로그램**을 가공하여 컴파일러가 실제로 번역할 소스 프로그램을 만드는 것

- 선행처리기 지시어(preprocessor directives)로 처리를 지시함

    - 선행처리기 지시어는 ‘#’로 시작함
    - 선행처리기 지시어 문장은 **한 행에 한 개**의 문장을 작성함
        - 세미콜론으로 문장을 구분짓지 않음.

- 대표적인 선행처리

    - 헤더파일 삽입 : #include
    - 매크로 선언 및 해제 : #define, #undef
    - 조건부 컴파일 : #if, #ifdef, #ifndef

- 선행 처리의 예  
    ![image](https://user-images.githubusercontent.com/66513003/136950040-4e3d1fcb-2c07-4546-ad3d-8f757ff923fc.png)

- 헤더파일을 include할 때, < >와 " "의 차이
    - <b>< >를 사용하는 경우</b>  
        C++ 프로그램을 컴파일 할 때, 컴파일러가 사용할 표준 라이브러리들이 모여있는 경로(include path)에서 해당 헤더를 검색하게 한다.
        <b>\<iostream></b>에는 cout, endl같은 기능들이 담겨있다.

    - <b>\" "를 사용하는 경우</b>  
        파일의 경로를 사용자가 직접 지정해준다.  
        <b>#include "a.h"</b>를 입력하면 현재 작업폴더에서 a.h 파일을 찾게된다.  
        만약 지정된 위치에 파일이 존재하지 않는 경우, **include path**에서 찾게되며, 여기서도 발견하지 못하는 경우 에러가 발생한다.

___

## **문장**

**C++ 프로그램의 문장**

- 하나의 문장은 단어와 연산자, 숫자, 문자, 문자열, 문장 부호,
빈칸 등을 정해진 문법에 따라 나열하여 작성함

- 문장의 끝에는 세미콜론(;)을 기입하여 다음 문장과 구분함

**블록(block)**

- 한 개 이상의 문장을 중괄호(‘{’와 ‘}’) 안에 나열하여
묶어 놓은 것

- 여러 개의 문장을 묶어 하나의 문장처럼 취급하거나
함수의 몸체를 구성하기 위해 사용됨

___

## **함수**

![image](https://user-images.githubusercontent.com/66513003/136956427-a72c5c8f-4f49-4b3a-8b69-2b442cf8e57f.png)

- 프로그램을 작성하는데 있어서 가장 기본이 되는 단위
- main() : 프로그램의 시작과 끝.
- cout이라는 객체를 통해서 문장을 출력

___

## **입출력 스트림**

### **std::cout 객체**

- 표준 출력 스트림 객체
- 데이터를 **문자열**로 변환하여 출력함
- 출력 연산자(삽입 연산자) : <<
    - 데이터를 표준 출력 스트림으로 삽입해주는 연산자

```cpp
std::cout << "나의 첫 번째 C++ 프로그램";

int a = 10;
std::cout << "a의 값은 ";
std::cout << a << "입니다." << std::endl;
```

### **std::cin 객체**

- 표준 입력 스트림 객체
- 문자열을 입력 변수의 자료형의 값으로 변환하여 입력함
- 입력 연산자(추출 연산자) : >>

```cpp
int a;
char str[100];
std::cin >> a >> str; // 10 가나다
// a에 10, str[100]에는 "가나다"가 입력이 됨.
```

## **명칭 공간(namespace)**

특정한 이름들이 인식되는 프로그램의 부분

- std::cin은 cin이라는 객체가 std라는 **명칭 공간**에 선언되어 있는 이름이라는 내용

- 명칭 공간의 정의
    ```cpp
    // myNspc : 명칭 공간의 이름
    namespace myNSpc {
        int count; // 명칭을 선언하는 문장 나열
    }

    // 명칭공간에 정의된 명칭의 사용
    myNSpc::count = 0;
    ```
- 명칭 공간이란?

    - 동일한 명칭이라도 서로 다른 명칭공간에서 정의되었다면 별개의 것으로 구분함.  
        여러 프로그래머가 작성한 프로그램을 결합하여 완성된 프로그램을 만들 경우 각자 필요한 명칭을 **독립적**으로 만들어 사용할 수 있음.

    - **전역 명칭공간**  
        특정 명칭공간에 속하지 않는 기본 명칭공간.

    - **std 명칭공간**  
        표준 C++ 라이브러리의 명칭들이 정의되어 있는 명칭공간.

- 명칭 공간의 사용 예
    ```cpp
    #include <iostream>
    namespace myNSp1 { int n = 10; }
    namespace myNSp2 { int n = 20; }
    int n = 30;

    int main()
    {
        int n = 40;
        std::cout << myNSp1::n << std::endl; // 10
        std::cout << myNSp2::n << std::endl; // 20
        std::cout << ::n << std::endl;       // 30
        std::cout << n << std::endl;         // 40
        return 0;
    }
    ```
    - int n = 40이 선언되지 않은경우, n은 전역변수(n=30)을 가리키게 됨.
    - 전역변수를 생성하지 않고, ::n을 호출하면 에러.

- 'using'을 이용한 명칭공간 사용

    - 특정 명칭공간이나 명칭공간 내의 특정 이름을 자주 사용하는 경우, 명칭공간 지정을 간소화 할 수 있음.

    ```cpp
    // std안에 들어있는 모든 이름은 명칭공간을 지정할 필요 없어짐.
    using namespace std;

    // 한 명칭 공간의 특정 이름만 편리하게 쓰고 싶을 때.
    using std::cout;
    using std::endl;
    ```
    
- 명칭공간 사용 예
    ```cpp
    #include <iostream>

    using namespace std; // namespace 사용 선언
    namespace myNSp1 { int n = 10; }
    namespace myNSp2 { int n = 20; }
    int n = 30;

    int main( )
    {
        int n = 40;
        cout << myNSp1::n << endl;
        cout << myNSp2::n << endl;
        cout << ::n << endl;
        cout << n << endl;
        return 0;
    }
    ```

- firstStep.cpp 에서 명칭 공간 사용시
    ```cpp
    #include <iostream>

    int main()
    {
    // 표준 출력 스트림으로 문장을 출력함
    std::cout << "나의 첫 번째 C++ 프로그램"
              << std::endl;
    return 0;
    }
    ```
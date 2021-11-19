# **05_C++_class_3**

## **목차**
1. 스택 클래스 - CharStack
2. 복소수 클래스 - Complex1
3. 심화 학습

___

## **1. 스택 클래스 - CharStack**

문자를 최대 20개까지 저장할 수 있는 스택을 나타내는 클래스를 선언하라. 스택 객체는 데이터를 저장(push)하거나 인출(pop)할 수 있으며, 스택이 비어있는지 가득 차 있는지 검사할 수 있다. 또한 이 스택을 이용하여 입력된 단어를 역순으로 출력하는 프로그램을 작성하라.

![image](https://user-images.githubusercontent.com/66513003/142583677-3d40328d-2c59-499b-a90f-0d41bbf4c0cc.png)

[CharStack.h](examples/ex07/CharStack.h)
[CharStack.cpp](examples/ex07/CharStack.cpp)

___

## **2. 복소수 클래스 - Complex1**

**# 복소수는 실수부와 허수부로 구성되는 수**
![image](https://user-images.githubusercontent.com/66513003/142604240-a78dd6b1-60e9-422d-bc58-8a1d8ad5077d.png)

**# 복소수 연산**
![image](https://user-images.githubusercontent.com/66513003/142604503-e999f5ce-65fb-4af9-9b6d-550368deb77a.png)

## **# Complex1 클래스**

![image](https://user-images.githubusercontent.com/66513003/142604843-7e16dcfa-97d2-4392-b269-d25752484bdc.png)

[Complex1.h](examples/ex07/complex1.h)
[Complex1.cpp](examples/ex07/complex1.cpp)

## **# 생성자 처리의 위임**

### **# 위임 생성자(delegating constructor)의 선언 (C++11 이후)**
- 초기화 리스트에 앞서 선언된 생성자를 사용하여 새로운 생성자를 선언할 수 있음
    - 위임 생성자 : 앞서 선언된 생성자를 이용하여 선언되는 생성자
    - 타겟 생성자 : 위임의 대상이 되는 생성자
- 생성자를 작성하는 코드의 중복을 줄일 수 있음

```cpp
#include <mem.h>

class MyObj
{
    int n;
    char *arr;

public:
    MyObj(int d, const char *a = nullptr) : n{d}
    {
        arr = new char[d];
        if (a)
            memcpy(arr, a, sizeof(char) * n);
        printf("%d %s", n, a);
    }
    // MyObj(const MyObj &ob) : n{ob.n}
    // {
    //     arr = new char[n];
    //     memcpy(arr, ob.arr, sizeof(char) * n);
    // }
    // 위 생성자 대신 아래로 교체
    MyObj(const MyObj &ob) : MyObj(ob.n, ob.arr) {}
    // 파라미터로 받는 값으로 첫번째 생성자를 호출 한다.
    // 복사 생성자가 할 일을 이 생성자에게 위임.
    // -> 위임 생성자.
};
```

## **# 초기화 리스트 생성자**

- 첫 번째 매개변수가 std::initializer_list<Type>인 생성자

### **# std::initializer_list 클래스**

- 지정된 자료형의 값들을 { } 안에 나열한 리스트
- std::initializer_list 클래스

![image](https://user-images.githubusercontent.com/66513003/142615823-f5da220d-95c0-4d15-ba95-5f33a8c6be11.png)

```cpp
#include <initializer_list>
using namespace std;

class VecF
{
    int n;
    float *arr;

public:
    VecF(int d, const float *a = nullptr) : n{d}
    {
        arr = new float[d];
        if (a)
            memcpy(arr, a, sizeof(float) * n);
    }
    // initializer_list 객체를 float 배열로 변환
    VecF(initializer_list<float> lst)
        : n{static_cast<int>(lst.size())} 
        // lst.size()는 int가 아닌 특수한 자료형이므로 static_cast로 정수형으로 형변환 
    {
        arr = new float[n];
        copy(lst.begin(), lst.end(), arr); // memcpy도 가능
        // 복사할 리스트의 시작과 끝 값을 지정해주고 복사받을 대상을 입력
    }
};

int main()
{
    float a[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    VecF v1(4, a);
    VecF v2{2.0f, 4.0f, 6.0f, 8.0f};
}
```

___

## **3. 심화 학습**
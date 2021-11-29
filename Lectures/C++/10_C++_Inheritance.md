# **C++ Inheritance**

## **목차**
1. 기초 클래스와 파생 클래스
2. 파생 클래스의 생성자 및 소멸자
3. 액세스 제어
4. 심화 학습

___

## **1. 기초 클래스와 파생 클래스**

### **# 파생 클래스의 선언**
```cpp
// 선언 형식
class DClassName : visibilitySpec BClassName {
    visibilitySpec_1:
    데이터 멤버 또는 멤버함수 리스트;
    visibiliySpec_2:
    데이터 멤버 또는 멤버함수 리스트;
    ······
};
```
- DClassName : 파생 클래스 이름
- BClassName : 기초 클래스 이름
- visibilitySpec : 가시성 지시어

[Person1.h](examples\ex10\2_Person.h)
[Student1.h](examples\ex10\2_Student.h)
[Stu_Main.cpp](examples\ex10\2_Stu_Main.cpp)

**# 실행 결과**
```
Dudley
Harry goes to Hogwarts
Harry
```

___

## **2. 파생 클래스의 생성자 및 소멸자**

![image](https://user-images.githubusercontent.com/66513003/143817937-d85d2f52-0eba-417b-a228-d49496778536.png)

### **# 생성자 및 소멸자의 실행 순서**

- 생성자 : **기초 클래스 생성자 → 파생 클래스 생성자**
    - 파생 클래스는 기초 클래스의 내용을 바탕으로 하고 있음
    - 객체의 기초 클래스 해당 내용이 먼저 준비된 후 파생 클래스에 선언된 내용을 초기화할 필요가 있음
- 소멸자 : **파생 클래스 소멸자 → 기초 클래스 소멸자**
    - 기초 클래스의 속성이 제거되기 전에 이를 활용할 가능성이 있는 파생 클래스 객체를 제거해야 함

[Person1.h](examples\ex10\2_Person.h)
[Student1.h](examples\ex10\2_Student.h)
[Stu_Main.cpp](examples\ex10\2_Stu_Main.cpp)

**# 실행 결과**
```
Person의 생성자
Student의 생성자
Harry goes to Hogwarts
Student의 소멸자
Person의 소멸자
```

___

## **3. 액세스 제어**

![image](https://user-images.githubusercontent.com/66513003/143819740-bb91e38f-36df-4a1d-b31d-f4209a1de2c2.png)

- 기초클래스로부터 상속받은 멤버의 가시성
    ![image](https://user-images.githubusercontent.com/66513003/143819892-5bf4fbe7-4b2c-400c-8610-99d35e17e88f.png)

![image](https://user-images.githubusercontent.com/66513003/143819981-44245991-5eff-418a-b23c-c5c9d02788f7.png)

![image](https://user-images.githubusercontent.com/66513003/143820005-486f68ab-93bb-485c-8973-ae2fc9c4d4f5.png)

___

## **4. 심화 학습**

### **# 파생 클래스 선언의 금지**

- final로 선언된 클래스는 파생 클래스를 더 이상 정의할 수 없음

```cpp
class A { ······ };
class B : public A { ······ };
class C final : public B { ······ };
class D : public C { ······ }; // 에러
```
- final은 키워드가 아닌 식별자(identifier)임
- final 클래스 지정과 같이 특별히 정해진 위치에 사용되지 않은 경우 식별자(예: 변수 이름)의 용도로 사용할 수도 있음(바람직한 용법은 아님)

### **# 이름 은폐(name hiding)**

- 어떠한 영역에서 그 영역을 내포하는 영역에 선언된 이름을 다시 선언하면 바깥 영역의 이름이 은폐됨

```cpp
#include <iostream>
using namespace std;

void f(int x)
{
    cout << "f(int x) --> " << x << endl;
}
void f(double x)
{
    cout << "f(double x) --> " << x << endl;
}
int main()
{
    f(10);   // f(int x) --> 10
    f(20.1); // f(double x) --> 20.1
}
```

```cpp
#include <iostream>
using namespace std;

void f(int x)
{
    cout << "f(int x) --> " << x << endl;
}
void f(double x)
{
    cout << "f(double x) --> " << x << endl;
}
int main()
{
    void f(int x);
    f(10);     // f(int x) --> 10
    f(20.1);   // f(int x) --> 20
    ::f(30.1); // f(double x) --> 30
}
```
- void f(int x);을 재선언해서 20.1을 담았는데도 int형으로 변환된다.
- ::f(30.1);은 정상적으로 실행된다.

```cpp
#include <iostream>
using namespace std;

void f(int x)
{
    cout << "f(int x) --> " << x << endl;
}
void f(const char *x)
{
    cout << "f(const char* x) --> " << x << endl;
}
int main()
{
    void f(int x);
    f(10);      // f(int x) --> 10
    f("abc");   // 함수 f의 매개변수가 int형이므로 에러
    ::f("abc"); // f(const char* x) --> abc
```
___

### **# 클래스 계층구조에서의 이름 은폐**
- 파생 클래스에서 기초 클래스에 선언된 이름을 다시 선언하면 기초 클래스에 선언된 이름이 은폐됨

```cpp
#include <iostream>
using namespace std;

class A
{
public:
    void f(int x)
    {
        cout << "A::f() --> " << x << endl;
    }
};
class B : public A
{
public:
    void f(double x)
    {
        cout << "B::f() --> " << x << endl;
    }
};
int main()
{
    B objB;
    objB.f(10.1); // B::f() --> 10.1
    objB.f(20);   // B::f() --> 20
}
```
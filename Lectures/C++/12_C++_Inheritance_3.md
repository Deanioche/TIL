# **C++ Inheritance 3**

## **목차**
1. 추상 클래스
2. 다중상속

___

## **1. 추상 클래스**

### **# 추상 클래스와 상세 클래스**

![image](https://user-images.githubusercontent.com/66513003/144002748-fe3785a9-2fcb-4526-802c-25c151b12c03.png)

- 유사한 성격을 갖는 클래스들의 공통적 요소들을 뽑아서 만든 클래스로, 일부 메소드의 구체적 구현이 없어 직접적인 사례가 존재하지 않는 클래스

- 추상 클래스로 객체를 직접 정의할 수 없음
    - 추상 클래스는 그 자체로 사용되는 것이 아니라 파생 클래스를 통해 구현되어 사용됨

### **# 추상클래스의 사용 목적**

- 사용 목적 : 특정 그룹에 속하는 클래스들(추상 클래스의 파생 클래스들)이 반드시 가지고 있어야 할 행위를 지정함으로써 필요한 행위를 정의하는 것을 누락하지 않도록 함

- 예 : 도형 클래스
- 도형 클래스 자체는 draw 및 move 등의 메소드를 정의할 수 없어 객체를 만들 수 없음
- 도형에 속하는 클래스(삼각형, 원 등)의 객체는 draw 및 move 등의 메소드가 정의되어 있어야 함을 지정함

### **# 상세 클래스**

- 클래스의 모든 요소가 구체적으로 구현되어 직접적인 사례가 존재하는 클래스
- 상세 클래스는 객체를 정의할 수 있음

- 예 : 삼각형 및 원 클래스
    - 추상 클래스인 ‘도형’에서 구현되지 않은 상태로 상속받은 draw, move 등을 구체적으로 정의할 수 있음
    - 삼각형이나 원 클래스의 객체를 정의할 수 있음

**# 멤버함수 중 순수가상함수가 포함된 클래스를 선언**

- 순수 가상함수 : 구현 부분이 없는 가상함수

    ![image](https://user-images.githubusercontent.com/66513003/144012757-920b69ca-4a64-4bfc-a0f7-8a1f6a61b106.png)

**# 순수가상함수를 포함하지 않는 클래스를 선언**

- 상속받은 순수 가상함수가 있다면 반드시 재정의해야 함
    ```cpp
    class AClass { // 추상 클래스
    public:
        virtual void vf() = 0; // 순수가상함수
        void f1() const
        { cout << "Abstract" << endl; }
    };
    class CClass : public AClass { // 상세 클래스
    public:
        void vf() { cout << "순수가상함수 구현" << endl; }
        void f2() const
        { cout << "Concrete" << endl; }
    };
    ```

### **# 추상 클래스의 활용**

**# 도형 클래스**
```
2차원 도형에 해당되는 원을 나타내는 클래스와 삼각형을 나타내는
클래스를 선언하고자 한다. 이 클래스들은 모두 공통적으로 도형이므로
도형을 그리기 위한 선의 색과 도형 내부를 채워 칠하기 위한 색을 속성
으로 가지고 있어야 하며, 이러한 속성을 이용하여 그리는 방법을 설명
할 수 있어야 한다. 또한 그래픽 객체를 (dx, dy)만큼 이동할 수 있으며,
2차원 좌표 원점을 기준으로 확대/축소하는 크기조정을 할 수 있다.
프로그램은 현재 속성이라는 객체가 있다. 속성 객체는 선의 색과 내
부 영역을 칠하기 위한 색을 표현하며, 그 값을 설정하거나 읽어낼 수
있다. 도형 객체를 만들면 현재 속성에 따라 만들어진다. 또한 도형 객
체의 선 색 및 채우기 색을 변경할 수 있다.
```

### **# GrAttrib 클래스**
![image](https://user-images.githubusercontent.com/66513003/144031675-152d0ff6-adb8-47b8-9336-b9e821601892.png)

```cpp
#include <iostream>

using namespace std;

class GrAttrib
{                     // 그래픽 속성 클래스
    string lineColor; // 선 색 속성
    string fillColor; // 내부 영역 색 속성
public:
    // 그래픽 속성 객체 생성자
    GrAttrib() : lineColor("검정색"), fillColor("흰색") {}
    GrAttrib(const string &lc, const string &fc)
        : lineColor(lc), fillColor(fc) {}
    // 속성 지정 멤버함수
    void setLineColor(const string &lc)
    {
        lineColor = lc;
    }
    void setFillColor(const string &fc)
    {
        fillColor = fc;
    }
    // 속성 값을 읽는 멤버함수
    string getLineColor() const
    {
        return lineColor;
    }
    string getFillColor() const
    {
        return fillColor;
    }
};
extern GrAttrib curAttrib; // 현재 속성을 나타내는 전역 객체
```

### **# Figure 클래스**

![image](https://user-images.githubusercontent.com/66513003/144036441-532c1fe5-93c2-4034-8652-6544fedd061a.png)

### **# Circle 클래스**

![image](https://user-images.githubusercontent.com/66513003/144037712-8fe5a560-3b9d-40aa-aa61-7f10e0d2df80.png)

[Circle.h](examples\ex12\Circle.h)
[Cir](examples\ex12\)
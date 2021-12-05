# **05_C++_class**


## **목차**
1. 객체지향 프로그래밍의 주요 개념
2. 클래스 선언과 객체 정의
3. 예제 - Counter 클래스
4. 생성자
5. 소멸자

___

## **1. 객체지향 프로그래밍의 주요 개념**

### **캡슐화(encapsulation)**

![image](https://user-images.githubusercontent.com/66513003/140866580-dc6ef8b3-c061-4fc2-8053-0ad4dc5445b7.png)

**캡슐화의 장점**

- 소프트웨어의 유지보수가 용이함  
    프로그램의 다른 부분에 영향을 미치지 않고 객체 내부 구현 방법을 수정할 수 있음
- 재사용이 용이함  
    잘 설계된 캡슐화된 객체는 다른 응용에서도 재사용할 수 있어 소프트웨어 개발 비용을 줄일 수 있음

![image](https://user-images.githubusercontent.com/66513003/140868049-6bee37e5-5879-4d7d-bec6-64333269f3ae.png)

___

## **2. 클래스 선언과 객체 정의**

### **가시성 지시어**

- 클래스의 멤버가 공개되는 범위를 나타냄
- 종류 : private, public, protected

### **private**

- 공개 범위
    - 소속 클래스의 멤버함수
    - 친구 클래스의 멤버함수 및 친구함수
    - 그 외의 범위에는 비공개

- 용도
    - 정보은닉을 위해 사용됨
    - 클래스의 구현을 위한 내부 상태(데이터 멤버)는 일반적으로 private으로 지정함

### **public**

- 공개 범위
    - 전 범위

- 용도
    - 주로 외부에 제공할 인터페이스를 공개하기 위해 사용됨

- 지시어 사용 예시
    ```cpp
    class CircleClass
    {
        C2dType center; // 중심 좌표
        double radius;  // 반경
    public:
        void init(double cx, double cy, double r) { ··· }
        double area() const { ··· }
        bool chkOverlap(const CircleClass &c) const { ··· }
        void display() const { ··· }
    };
    ```

___

## **3. 예제 - Counter 클래스**

### **# 소스 파일의 구성**

![image](https://user-images.githubusercontent.com/66513003/140868883-6ec8bd01-f3ca-4f49-91b2-5e11871d8509.png)

### **헤더파일 내용의 중복 include 방지**

![image](https://user-images.githubusercontent.com/66513003/140870065-dfc93c9d-956f-4f68-9c77-abc3e4eafcb0.png)

![image](https://user-images.githubusercontent.com/66513003/140870078-66387027-684b-4830-b233-84ddcde608b7.png)

___

## **4. 생성자**

### **생성자 선언 형식**

![image](https://user-images.githubusercontent.com/66513003/140870643-6f0e2be3-e137-4ec9-b100-a6e4ea8cc492.png)

### **초기화 리스트**

- 생성자의 머리에 데이터 멤버를 초기화하는 값들을 나열한 리스트

- ‘데이터멤버이름{초깃값}’ 형태로 초깃값을 지정

![image](https://user-images.githubusercontent.com/66513003/140871516-8caacc0a-313d-4086-ab80-61bd690502e3.png)

___

## **5. 소멸자**

- 객체가 **소멸될 때 수행할 작업을 정의**하는 특수한 멤버함수

### **소멸자의 특성**

- 클래스의 이름에 ‘ ~ ’를 붙여 선언함
- 소멸자 머리에 반환 자료형을 표시하지 않으며, return 명령으로 값을 반환할 수 없음
- 매개변수를 포함할 수 없음
- 다중정의할 수 없으며, 클래스에 하나만 정의함
- public으로 선언하는 것이 일반적임
- 상속을 통해 파생 클래스를 정의하는 경우 virtual을 지정하여 가상함수가 되도록 하는 것이 좋음

### **소멸자 선언 형식**

![image](https://user-images.githubusercontent.com/66513003/140871764-08c0ef97-e2bf-4df0-9f38-81f73944d3cb.png)

- 예시
    [Person.cpp](examples/Person/Person.cpp)
    [Person.h](examples/Person/Person.h)

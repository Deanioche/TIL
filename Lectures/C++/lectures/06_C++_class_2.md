# **05_C++_class_2**

## **학습 목표**
1. 디폴트 생성자를 정의하여 활용할 수 있다.
1. 복사 생성자 및 이동 생성자를 용도에 맞게 정의하여 활용할 수 있다.
1. static 데이터 멤버 및 static 멤버함수를 활용할 수 있다.


## **목차**
1. 디폴트 생성자
2. 복사 생성자
3. 이동 생성자
4. static 데이터 멤버와 static 멤버함수

___

## **1. 디폴트 생성자**

- 매개변수가 없는 생성자
- 모든 매개변수에 디폴트 인수가 지정된 생성자

- 클래스를 선언할 때 생성자를 선언하지 않으면 컴파일러는 묵시적으로 디폴트 생성자를 정의한다.
    - 묵시적 디폴트 생성자는 아무런 동작도 하지 않음.
- 생성자를 하나라도 선언하면 컴파일러는 묵시적 디폴트 생성자를 정의하지 않음

### **# 생성자를 선언한 클래스**
```cpp
class CounterM
{
    const int maxValue;
    int value;

public:
    CounterM(int mVal) // 생성자 지정
        : maxValue{mVal}, value{0} {}
    void reset() { value = 0; }
    void count()
    {
        value = value < maxValue ? value + 1 : 0;
    }
};
```
위와 같이 생성자를 선언한 상태에서는 다음과 같은 경우에 에러가 뜬다.

- 아무런 값도 지정해 주지 않는 경우
    ```cpp
    int main()
    {
        CounterM cnt1(999);
        CounterM cnt2; // 에러 - "CounterM" 클래스의 기본 생성자가 없습니다.
    }
    ```
- 객체를 배열 또는 포인터로 생성하는 경우
    ```cpp
    int main()
    {
        CounterM cntMArr1[3]; // 에러(기본 생성자가 없음)
        CounterM cntMArr2[3] =
            {CounterM(9), CounterM(99),
            CounterM(999)}; // 값들을 모두 지정해 주는 경우 OK
        CounterM *pt =
            new CounterM[10]; // 에러(기본 생성자가 없음)
    }
    ```

### **# 생성자를 선언하지 않은 클래스**
```cpp
class Counter
{
    int Value;

public:
    // Counter() {} 디폴트 생성자
    void reset() { value = 0; }
    void count() { ++value; }
    int getValue() const
    {
        return value;
    }
};
```

- 배열 & 포인터 생성이 가능
    ```cpp 
    int main()
    {
        Counter cntArr[4];             // OK
        Counter *pt = new Counter[10]; // OK
    }
    ```

[Constructor_prec.cpp](examples/Constructor_prec.cpp)
```cpp
#include <stdio.h>

class Object
{
    const int a;
    int b;

public:
    Object(int a) : a(a), b{9} {}
    void p()
    {
        printf("%d ", a);
        printf("%d\n", b);
    }
};

int main()
{
    Object t(10);
    t.p(); // 10 9

    Object t2{t};
    t2.p(); // 10 9

    Object t3 = t2;
    t3.p(); // 10 9

    Object tarr[3]{1, 2, 3};
    tarr[0].p(); // 1 9
    tarr[1].p(); // 2 9
    tarr[2].p(); // 3 9

    Object *tp = new Object[2]{1, 2};
}

```

___

## **2. 복사 생성자**

- 같은 클래스의 객체를 복사하여 객체를 만드는 생성자
- 묵시적 복사 생성자 : 객체의 데이터 멤버들을 그대로 복사하여 객체를 만들도록 묵시적으로 정의된 복사 생성자

### **명시적으로 복사 생성자를 정의하는 형식**

![image](https://user-images.githubusercontent.com/66513003/141803135-536c1702-f0b7-4277-bb90-c893475862b6.png)

### **묵시적 복사 생성자**

![image](https://user-images.githubusercontent.com/66513003/141804703-f52ec512-8efe-45f3-8bcc-72bf43ecd15e.png)

생성자 파라미터 는 int만 받지만, 대신 CounterM 객체를 담아 복사 할 수 있다.

즉, 아래처럼 복사 생성자가 숨겨져 있다.
```cpp
class CounterM
{
    const int maxValue;
    int value;

public:
    CounterM(int mVal)
        : maxValue{mVal}, value{0} {}
    CounterM(const CounterM &c) : maxValue{c.maxValue}, 
                                  value{c.value} {}
    void reset() { value = 0; }
};
```

## **# 얕은 복사의 문제점**

### **# VecF 클래스**
벡터 객체를 만들 수 있는 VecF 클래스를 정의하고자 한다. VecF 객체는 저장할
수 있는 float 값의 수를 인수로 지정하여 생성되며, 저장할 값의 배열이 제공될
경우 그 값으로 초기화한다. 인수로 전달된 VecF 객체와 덧셈한 결과를 반환할 수
있으며, 객체에 저장된 벡터를 출력할 수 있다.

![image](https://user-images.githubusercontent.com/66513003/141947721-d67ce3fc-c697-464e-a5f8-0f1e93a9eeec.png)

[VecF.h](examples\ex06\VecF.h)
[VFMain1.cpp](examples\ex06\VFMain1.cpp)

![image](https://user-images.githubusercontent.com/66513003/141956266-7cd3ef13-740f-4570-ae4d-f7157a720eea.png)

- **얕은 복사**는 객체 간에 내부에 저장된 값의 주소가 **공유**되므로 객체 소멸시 delete[]가 여러번 반복되는데, 한번 delete된 메모리를 다시 delete 시도하는 경우, 시스템이 사용 권한이 없는 매모리에 접근한다고 보고 에러를 발생 시킴.

그러므로 객체간 완전히 분리된 복사가 필요.

## **깊은 복사**

```cpp
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
    // #1 복사 생성자 지정
    VecF(const VecF &fv) : n{fv.n}
    {
        arr = new float[n];
        memcpy(arr, fv.arr, sizeof(float) * n);
    }
}
```
VecF의 복사 생성자(#1)를 다음과 같이 정의하면, 우선 const VecF &fv에서 파라미터로 받은 객체를 참조해오지만 const 상수이므로 이 객체의 데이터가 수정되는 일은 없다.

받은 객체의 데이터 길이(n)을 받아 새 배열을 초기화하고 memcpy()함수로 데이터를 복사한다.

```cpp
VecF v2(v1);
```
이제 위 코드는 객체를 깊게(완벽하게) 복사한다.

___

## **3. 이동 생성자**

객체를 계속 복사하다보면, 메모리가 계속 사용되어 효율성이 떨어지는 문제가 발생하므로, 이동생성자로 개선시킬 수 있다.

**# 불필요한 복사의 비효율성**

![image](https://user-images.githubusercontent.com/66513003/141982124-f5cbb997-b737-47b2-8568-36b67eaf17d5.png)

복사중 tmp객체가 새로 생성되어 메모리를 차지.

## **l-value 참조와 r-value 참조 비교**
![image](https://user-images.githubusercontent.com/66513003/141982541-0b4ecf75-8a78-477a-892b-ad5a4945c6be.png)

- r-value 참조의 선언
    - ‘&’ 기호로 선언하는 l-value 참조와 달리 r-value 참조는 ‘&&’ 기호로 선언함

- l-value 참조와 r-value 참조의 사용 예
    ```cpp
    VecF v1(3), v2(3);
    VecF& vLRef = v1; // l-value 참조로 l-value를 참조함
    int& a = 10; // 오류: l-value 참조로 r-value를 참조할 수 없음
    const int& b = 20; // 상수 l-value 참조로는 r-value를 참조할 수 있음
    int&& c = 30; // r-value는 r-value 참조로 참조할 수 있음
    VecF&& vRRef1 = v1.add(v2); // 함수의 반환 객체는 r-value임
    VecF&& vRRef2 = v2; // 오류: r-value 참조로 l-value를 참조할 수 없음
    ```

- r-value 참조를 이용한 이동 생성자 
    ```cpp
    #include <iostream>
    #include <cstring>
    using namespace std;

    class Vec
    {
        int n;
        int *arr;

    public:
        Vec(int d, const int *a = nullptr) : n{d}
        {
            arr = new int[d];
            if (a)
                memcpy(arr, a, sizeof(int) * n);
        }
        Vec(Vec &&fv, int l) : n{fv.n}, arr{fv.arr}
        {
            printf("\nr-value 참조 복사\n");
            fv.arr = nullptr;
            fv.n = 0;
        }
        Vec(const Vec &fv) : n{fv.n}
        {
            printf("\nl-value 참조 복사\n");
            arr = new int[n];
            memcpy(arr, fv.arr, sizeof(int) * n);
        }
        ~Vec()
        {
            delete[] arr;
        }
        void print() const
        {
            cout << "[ ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << "]";
        }
        Vec add(const Vec &fv) const
        {
            printf("\nadd\n");
            Vec tmp = Vec(n); // 벡터의 덧셈 결과를 저장할 임시 객체
            for (int i = 0; i < n; i++)
            {
                tmp.arr[i] = arr[i] + fv.arr[i];
            }
            return tmp; // 덧셈 결과를 반환함
        }
    };

    int main()
    {
        int a[] = {1, 2, 3};
        int b[] = {2, 3, 4};
        Vec v1(3, a);

        Vec v2(3, b);
        Vec v3{v1.add(v2)}; // r-value 참조 복사
        // add() 후 return으로 반환되는 tmp 객체는 r-value이므로, 이동생성자 Vec(Vec&& fv)로 들어가게 된다.

        v3.print();
    }
    ```
    l-value 참조인 복사 생성자가 실행될 수도 있지만, 이동생성자의 파라미터는 Vec&& 으로, r-value 값이 들어오는 경우, 우선적으로 동작한다.

### **복사, 이동 생성자 사용 예시**
[copy_move_Constructor_test](examples\ex06\copy_move_Constructor_test.cpp)
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class A
{
    int a;

public:
    A(int n) : a{n}
    {
        printf("값 저장됨. a : %d\n", n);
    }
    A(A &v) : a{v.a}
    {
        printf("복사 생성자 호출됨. a : %d\n", v.a);
    }
    A(A &&v) : a{v.a}
    {
        printf("이동 생성자 호출됨. a : %d\n", v.a);
    }
    ~A()
    {
        printf("객체 삭제\n");
    }
    void p()
    {
        printf("프린트 a : %d\n", this->a);
    }
    A r(A a)
    {
        return a;
    }
};

int main()
{
    A a(1);      // 값 저장됨.
    A b(a);      // 복사 생성자 호출됨. a : 1
    A c(b.r(a)); // 복사 생성자 호출됨. a : 1
                 // 이동 생성자 호출됨. a : 1

    c.p(); // 프린트 a : 1

    // 객체 삭제
    // 객체 삭제
    // 객체 삭제
    // 객체 삭제
    return (0);
}
```

___

## **4. static 데이터 멤버와 static 멤버함수**

### **# static 데이터 멤버**
![image](https://user-images.githubusercontent.com/66513003/142018999-af3a1bb0-665b-4c62-9972-495cb9e46a9f.png)

### **# static 멤버함수**
- 특정 객체에 대한 처리를 하는 것이 아니라, 소속 클래스 단위의 작업을 수행하는 함수
- static 멤버함수는 객체가 정의되지 않아도 사용할 수 있음
- static 멤버함수 안에서는 일반 멤버를 사용할 수 없으며, static 멤버만 사용할 수 있음

### **NamedObj 클래스**

이름을 갖는 객체를 만들 수 있는 클래스를 정의하고자 한다. 객체가 생성될 때 고유번호를 가지게 되는데, 이 번호는 NamedObj 객체가 생성됨에 따라 1번부터 시작하여 차례로 부여되는 일련번호이다. 객체는
자기 자신의 일련번호와 이름을 출력할 수 있으며, 현재 존재하는 NamedObj 클래스의 객체 수를 구할 수 있다.

![image](https://user-images.githubusercontent.com/66513003/142019924-720ec116-3422-4107-9ae0-93ff2a96a385.png)


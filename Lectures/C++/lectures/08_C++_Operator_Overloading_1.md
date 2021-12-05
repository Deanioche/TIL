# **08_C++_Operator_Overloading_1**

## **목차**
1. 연산자 다중정의의 개념
2. 단항 연산자의 다중정의
3. 이항 연산자의 다중정의
4. 스트림 출력 연산자의 다중정의

___

## **1. 연산자 다중정의의 개념**

### **# 피연산자의 자료형과 연산자**

- 동일한 연산자라도 구체적인 처리 방법은 피연산자의 자료형에 따라 다름

    ![image](https://user-images.githubusercontent.com/66513003/142716694-127b2d7b-794a-4c56-a57a-8dda4f890eb1.png)


- 연산자 다중정의는 C++에 정의된 연산자를 사용자가 선언한 클래스의 객체에 대하여 사용할 수 있도록 정의 하는 것.

### **# 연산자 다중정의를 할 때 주의사항**

- 연산자의 의미를 임의로 바꾸지 않는다.
- 정의를 할 때는 연산자의 고유한 특성이 유지되도록 한다.
    - 연산자의 우선순위나 피연산자 수 불변
    - 전위 표기와 후위 표기 연산자의 의미 유지

### **# 주요 연산자 다중정의 대상**

- 클래스의 객체 간 대입 및 이동 대입 연산자
    - 특히 동적 할당을 받는 포인터를 포함하는 경우 고려할 필요가 있음
- 수치형 객체의 산술 연산자 다중정의
    - 교환법칙도 함께 고려함
- 두 객체를 비교하기 위한 관계 연산자의 다중정의
- 스트림 입력 및 출력을 위한 >>, << 연산자

### **# 다중정의를 할 수 없는 연산자**

- 멤버 선택 연산자 [ . ]
- 멤버에 대한 포인터 연산자 [ .* ]
- 유효범위 결정 연산자 [ :: ]
- 조건 연산자 [ ? : ]

### **# 연산자 다중정의 위치**
- 클래스의 멤버로 정의하는 방법
    - 연산자의 구현 과정에서 객체의 멤버를 액세스 할 수 있음
- 클래스 외부에서 정의하는 방법
    - 클래스의 멤버가 아니므로, 객체의 private 멤버는 임의로 사용할 수 없음

___

## **2. 단항 연산자의 다중정의**

### **# 단항 연산자**

- 피연산자가 1개인 연산자
- 전위 표기법과 후위 표기법

![image](https://user-images.githubusercontent.com/66513003/142716979-6ba84211-6ae9-4390-b02f-10bb0e610cc7.png)

### **# 다중정의 형식**

```cpp
ReturnClass ClassName::operator opSymbol()
{
    ······
}
```
- opSymbol : ++, -- 등의 단항 연산자 기호
- 형식 매개변수 없음

### **# 전위 표기법 단항 연산자의 다중정의**

```cpp
// 예시 1
class IntClass1 {
    int a;
public:
    IntClass1(int n=0) : a(n) {} // 생성자
    IntClass1& operator ++ () { // 전위 표기 ++ 연산자 다중정의
        ++a;
        return *this;
    }
    int getValue() const { return a; }
};

IntClass1 i;
cout << (++i).getValue() << endl; // 1 
```
```cpp
// 예시 2
class Int
{
    int i;

public:
    Int(int n = 0) : i(n) {}
    Int &operator~()
    {
        i *= 2;
        return *this;
    }
    int p() const { return i; }
};

int main(int argc, char const *argv[])
{
    Int i = 1;
    cout << i.p() << endl;    // 1
    cout << (~i).p() << endl; // 2
    return 0;
}
```

### **# 후위 표기법 단항 연산자의 다중정의**

```cpp
ReturnClass ClassName::operator opSymbol(int)
{
    ······
}
```

- opSymbol : ++, -- 등의 단항 연산자 기호
- 형식 매개변수 표기 위치의 ‘int’는 **인수 전달의 의미가 아니라** 단지 후위 표기법을 사용하는 단항 연산자임을 나타냄

```cpp
// 예시
class IntClass2
{
    int a;

public:
    IntClass2(int n = 0) : a(n) {} // 생성자
    IntClass2 operator++(int)
    { // 후위 표기 ++ 연산자 다중정의
        IntClass2 tmp(*this);
        ++a;
        return tmp;
    }
    int getValue() const { return a; }
};

int main(int argc, char const *argv[])
{
    IntClass2 i;
    cout << (i++).getValue() << endl;
    return 0;
}
```
```cpp
// 예시 2
#include <iostream>
using namespace std;

class Int
{
    int i;

public:
    Int(int n = 0) : i(n) {}
    Int &operator++(int) // int를 담아 후위연산자 정의
    {                   // 참조 값을 반환하는 이유는 b++ = 10 과 같은 연산을 가능하게 하기 위해
        i *= 3;
        return *this;
    }
    Int operator++() // 복사한 객체를 리턴.
    {
        Int t(*this);
        i *= 10; // i객체의 i값만 변하고 t객체는 그대로
        return t;
    }
    Int &operator~() // 전위연산자 정의
    {                // 참조 값을 반환
        i += 2;
        return *this;
    }
    int p() const { return i; }
};

int main(int argc, char const *argv[])
{
    Int i = 10;
    cout << (~i).p() << endl;   // 12
    cout << (++i).p() << endl;  // 12 t객체의 i값. i객체의 i값은 *= 10 됨
    cout << (~i).p() << endl;   // 122
    cout << (i++).p() << endl;  // 366
    cout << (~i).p() << endl;   // 368
    cout << (~i++).p() << endl; // 1106 ++ 연산 우선
    return 0;
}
```
- `Int &operator++(int)` 에서 참조 값을 반환하는 이유는 `++b = 10`과 같은 연산을 가능하게 하기 위해

___

## **3. 이항 연산자의 다중정의**

### **# 다중정의 형식**

```cpp
ReturnClass ClassName::operator opSymbol(ArgClass arg)
{
    ······
}
```
- opSymbol : +, -, *, /, &&, || 등의 이항 연산자 기호
- 객체 자신이 좌측 피연산자, arg가 우측 피연산자에 해당됨

### **# 복소수 객체와 복소수 객체의 덧셈 연산자**

![image](https://user-images.githubusercontent.com/66513003/143457799-06c33227-c0dd-4102-a15d-6e36a453dee2.png)

- **수식 : complex2Obj1 + complex2Obj2**

    ```cpp
    Complex2 Complex2::operator + (const Complex2 &c) const
    {
        Complex2 tmp(*this);
        tmp.rPart += c.rPart;
        tmp.iPart += c.iPart;
        return tmp;
    }
    // => return Complex2(rPart+c.rPart, iPart+c.iPart);
    ```

### **복소수 객체와 실수의 덧셈 연산자**

- **수식 : complex2Obj + 10.0**

    ```cpp
    Complex2 Complex2::operator + (double r) const
    {
        return Complex2(rPart + r, iPart);
    }
    ```
    - Complex2(double r=0, double i=0)이라는 생성자가 정의되어 있어 double값이 묵시적으로 Complex2 객체로 형변환되므로, 이 연산자를 정의하지 않아도 Complex2 객체간 덧셈 연산자를 이용하여 수식을 처리할 수 있음

- 예제
    ```cpp
    #include <iostream>
    using namespace std;

    class Int
    {
        int i;

    public:
        Int(int n = 0) : i(n) {}
        Int operator+(int r)
        {
            i += r;
            return *this;
        }
        Int operator+()
        {
            return i;
        }
        int p() const { return i; }
    };

    int main(int argc, char const *argv[])
    {
        Int i = 10;
        cout << (+i).p() << endl;      // 10
        cout << (i + 3.5).p() << endl; // 13 -> 소수점 잘림
        return 0;
    }
    ```


### **실수와 복소수 객체의 덧셈 연산자**

- 좌측 피연산자가 실수이므로 Complex2 클래스의 멤버로 연산자를 정의할 수 없음
    - 클래스에 속하지 않는 외부의 별도 연산자로 정의함

![image](https://user-images.githubusercontent.com/66513003/143686050-25eab5da-8391-4451-95c5-62ba37815df6.png)

- friend를 붙이면 private 멤버를 수정할 수 있게 해준다.
___

## **4. 스트림 출력 연산자의 다중정의**

### **# << 연산자를 정의할 위치**

![image](https://user-images.githubusercontent.com/66513003/143687108-84a8bfc8-6f1d-4050-ab27-613948e3bcb9.png)

- 클래스에 속하지 않는 외부의 별도 연산자로 정의함
- << 연산자가 Complex2 객체의 private 멤버를 액세스할 수 있게 friend로 지정

### **# << 연산자가 반환할 값**

- cout을 통한 연속적인 출력 문장

    ![image](https://user-images.githubusercontent.com/66513003/143687126-fb6563a2-4f9c-4d1b-b863-f5f1ab712e6d.png)

### **# 스트림 출력 연산자 다중정의 예**

```cpp
#include <iostream>
using namespace std;

class Complex2
{
    double rPart, iPart;

public:
    Complex2(double r = 0, double i = 0) : rPart(r), iPart(i) {}

    Complex2 operator+(const Complex2 &c) const
    {
        Complex2 tmp(*this);
        tmp.rPart += c.rPart;
        tmp.iPart += c.iPart;
        return tmp;
    }

    /* << 연산자 다중정의 */
    friend ostream &operator<<(ostream &os, const Complex2 &c);
};

/*왼쪽항 cout(os) || 우측항 대입할 변수(c)*/
ostream &operator<<(ostream &os, const Complex2 &c)
{
    os << "(" << c.rPart;
    if (c.iPart > 0)
        os << "+j" << c.iPart;
    else if (c.iPart < 0)
        os << "-j" << -c.iPart;
    os << ")";
    return os;
}

int main()
{
    Complex2 a(12, 34);
    Complex2 b(10, -12);
    cout << a << " + " << b << " = " << a + b << endl;
    return 0;
}
```
- 출력 결과
    ```
    (12+j34) + (10-j12) = (22+j22)
    ```

___

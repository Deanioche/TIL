# **09_C++_Operator_Overloading_2**

## **목차**

1. 대입 및 이동 대입 연산자
2. [] 연산자의 다중정의
3. 문자열 클래스
4. 자료형의 변환

___

## **1. 대입 및 이동 대입 연산자**

### **# 대입 연산자 (=)**

- 묵시적인 대입 연산자 : 우측 피연산자 데이터 멤버를 좌측 피연산자에 그대로 복사함
- 객체에 동적 할당된 메모리를 가리키는 포인터가 포함되어 있을 경우 얕은 복사로 인해 의도하지 않은 **공유 상태**의 문제가 발생할 수 있음
- 깊은 복사를 할 수 있는 대입 연산자를 다중정의할 필요가 있음

### **# VecF 클래스의 대입 연산자 다중정의**

- VecF 클래스 정의 (VecF.h)
    ```cpp
    #include <iostream>
    #include <cstring>
    using namespace std;
    class VecF
    {
        int n; // 배열arr의 길이
        float *arr;

    public:
        VecF(int d, const float *a = nullptr) : n{d}
        {
            arr = new float[d];
            if (a)
                memcpy(arr, a, sizeof(float) * n);
            // arr 주소에 a에 담긴 값을 n 길이만큼 복사
        }
        // 복사 생성자 지정
        VecF(const VecF &fv) : n{fv.n}
        {
            arr = new float[n];
            memcpy(arr, fv.arr, sizeof(float) * n);
        }
        ~VecF()
        {
            delete[] arr;
        }
        VecF add(const VecF &fv) const
        {
            VecF tmp = VecF(n); // 벡터의 덧셈 결과를 저장할 임시 객체
            for (int i = 0; i < n; i++)
            {
                tmp.arr[i] = arr[i] + fv.arr[i];
            }
            return tmp; // 덧셈 결과를 반환함
        }
        void print() const
        {
            cout << "[ ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << "]";
        }
    };
    ```

- 대입 연산자 다중 정의
    ```cpp
    VecF &VecF::operator=(const VecF &fv)
    {
        if (n != fv.n)
        {                              // 벡터의 크기가 다르다면
            delete[] arr;              // 기존 메모리를 반환하고
            arr = new float[n = fv.n]; // 새로 메모리를 할당함
        }
        memcpy(arr, fv.arr, sizeof(float) * n); // 데이터 복사
        return *this;
    }
    ```

### **# 이동 대입 연산자 (=)**
- 좌측 피연산자에 대입할 우측 피연산자가 r-value일 때 사용됨
    - 대입 후 우측 피연산자의 내용이 더 이상 필요 없는 상황
- 우측 피연산자의 내용을 좌측 피연산자로 이동하여 불필요한 복사를 피함으로써 효율성을 높일 수 있음

- VecF 클래스의 이동 대입 연산자 다중정의
    ```cpp
    VecF &VecF::operator=(VecF &&fv)
    {
        delete[] arr; // 기존 메모리를 반환하고
        n = fv.n;     // 우측 피연산자의 내용을 이동함
        arr = fv.arr;
        fv.arr = nullptr;
        return *this;
    }
    ```

### **# 대입 및 이동 대입 연산자의 활용**

```cpp
int main()
{
    float a[3] = {1, 2, 3};
    float b[3] = {2, 4, 6};
    VecF v1(3, a);
    VecF v2(3, b);
    VecF v3(3);
    v3 = v1; // l-value, 대입 연산자
    cout << v3 << endl;
    v3 = v1.add(v2); // 이동 대입 연산자
    cout << v1 << " + " << v2 << " = ";
    cout << v3 << endl;
    return 0;
}
// 출력 
// [ 1 2 3 ]
// [ 1 2 3 ] + [ 2 4 6 ] = [ 3 6 9 ]
```

### **# std::move 함수의 활용**

- 두 VecF 객체를 교환하는 함수의 구현
    ![image](https://user-images.githubusercontent.com/66513003/143770680-e3bf38f7-9696-4fc6-92a5-79600e07dede.png) 

- **std::move 함수**
    
    인수로 전달되는 객체의 r-value 참조를 반환

    - 예 : VecF tmp = std::move(v1);
        - v1의 r-value 참조를 구하여 tmp의 초기화에 사용
        - 이동 생성자를 이용하여 tmp 생성
    - 예 : v1 = std::move(v2);
        - v2의 r-value 참조를 구하여 v1에 대입
        - 이동 대입 연산자 실행

- 두 VecF 객체를 교환하는 함수의 구현 
    ```cpp
    // swap 함수
    void swapVecF(VecF& v1, VecF& v2) {
        VecF tmp = move(v1); // 이동 생성자
        v1 = move(v2); // 이동 대입 연산자 사용
        v2 = move(tmp); // 이동 대입 연산자 사용
    }

    // main
    int main() {
        float a[3] = {1, 2, 3};
        float b[3] = {2, 4, 6};
        VecF vec1(3, a), vec2(3, b); // vec1과 vec2를 swap
        swapVecF(vec1, vec2);
    }
    ```

    ![image](https://user-images.githubusercontent.com/66513003/143771191-5b0a22ec-0b18-4eaa-b905-4ef34391ae92.png)

___

## **2. [] 연산자의 다중정의**

### **# SafeIntArray 클래스 구성**

- 요구사항
    - 배열처럼 지정된 개수의 int 값을 저장할 수 있다.
        - 예 : SafeIntArray a(10); 10개의 int 값을 저장하는 객체
    - 각각의 값들은 0번부터 시작하는 일련번호를 첨자로 지정하여 액세스한다.
        - 예 : a[5] = 10; 6번째 위치에 10을 저장함
    - 첨자가 지정된 범위를 벗어날 경우 오류 메시지를 출력한 후 프로그램을 종료한다.
        - 예 : cout << a[11];

- **[] 연산자**
    - 배열의 첨자를 지정하는 이항 연산자
    - SafeIntArray a(10);

- 데이터를 저장하기 위해 사용할 [] 연산자
    ![image](https://user-images.githubusercontent.com/66513003/143771306-cb1e5b8d-b8e7-492a-b40c-cb73532a35d4.png)

SafeIntArray.h
```cpp
#include <iostream>
class SafeIntArray
{
    int limit; // 원소의 개수
    int *arr;  // 데이터 저장공간
public:
    SafeIntArray(int n) : limit(n)
    {
        arr = new int[n]; // 공간 할당
    }
    ~SafeIntArray()
    {
        delete[] arr;
    }
    int size() const { return limit; }
    // i번 원소를 반환하는 멤버함수
    int &operator[](int i)
    {
        if (i < 0 || i >= limit)
        {
            std::cout << "첨자가 범위를 벗어나 프로그램을 종료합니다.";
            exit(EXIT_FAILURE);
        }
        return arr[i]; // i번 원소 반환
    }
    int operator[](int i) const
    {
        if (i < 0 || i >= limit)
        {
            std::cout << "첨자가 범위를 벗어나 프로그램을 종료합니다.";
            exit(EXIT_FAILURE);
        }
        return arr[i]; // i번 원소 반환
    }
};
```
SafeArr.cpp
```cpp
#include <iostream>
#include "SafeIntArray.h"
using namespace std;
int main()
{
    SafeIntArray a(10); // 10개의 원소를 갖는 객체 생성
    for (int i = 0; i < 10; i++)
        a[i] = i;
    cout << a[5] << endl;  // 올바른 범위의 원소 액세스
    cout << a[12] << endl; // 범위를 벗어난 액세스
    return 0;
}
```
**# 출력 결과**
```
5
첨자가 범위를 벗어나 프로그램을 종료합니다.
```

___

## **3. 문자열 클래스**

### **# 문자열의 저장**

- 문자열의 끝을 알리기 위해 널(null) 문자('\0')를 사용함
    - Null-terminated string

- 문자열을 저장하기 위한 char형 배열

    ![image](https://user-images.githubusercontent.com/66513003/143772284-5746377c-34f9-438a-9382-ec47d09ab03f.png)

- 문자열 리터럴

    ![image](https://user-images.githubusercontent.com/66513003/143772329-cc79a118-e9a8-4a9c-921c-0e3b9aadc841.png)

### **# C 스타일 문자열 처리 함수(헤더 파일 : #include <cstring>)**
![image](https://user-images.githubusercontent.com/66513003/143772360-3103fdc8-5e57-458f-86fb-7879f54a889e.png)
![image](https://user-images.githubusercontent.com/66513003/143772501-46d68877-93c4-463a-a8cf-7327853953ed.png)

### **# MyString 클래스**

- 요구사항
    - 문자열을 저장하되 다음의 다중정의된 연산자를 포함하며, 실행시 필요에 따라 저장공간을 늘릴 수 있음

    ![image](https://user-images.githubusercontent.com/66513003/143772535-bee42289-631f-4ccc-9d0d-df244bad108b.png)

    - 생성자 및 소멸자
        ```
        MyString();
        MyString(const char* str);
        MyString(const MyString& mstr);
        MyString(MyString&& mstr);
        MyString(int s); // private - 내부용으로만 사용함
        ~MyString();
        ```
    - 기타 메소드
        ```
        int length() const; // 문자열 길이 반환
        ```
    - 데이터 멤버
        ![image](https://user-images.githubusercontent.com/66513003/143772592-49f35cd1-3a81-4df0-b000-6759cbd8945e.png)

    [MyStringMain.cpp](examples/ex08/MyStringMain.cpp)
    [MyString.cpp](examples/ex08/MyString.cpp)
    [MyString.h](examples/ex08/MyString.h)

### **string이란?**

- 문자열을 저장하기 위한 표준 C++ 라이브러리의 클래스
    ```
    basic_string<char>
    ```

- 헤더파일 : #include <string>
- 연산자 
    ```
    [], +, =, +=, ==, !=, >, >=, <, <=, 스트림 입출력(<<, >>) 등
    ```
- 멤버함수 : length, append, find, c_str 등
- 함수 : stoi, stod, to_string, swap, getline 등

___

## **4. 자료형의 변환**

### **# 묵시적 형 변환**
- MyString 클래스의 묵시적 형 변환
    ![image](https://user-images.githubusercontent.com/66513003/143773233-0c015c16-c95b-4a89-afb8-b6f82c27a115.png)

### **# 값을 제공하는 송신 측 클래스에서 정의하는 방법**
    - 값을 받는 수신 측 클래스의 이름으로 연산자를 정의함
    - 예 : MyString 클래스의 객체를 C 스타일 문자열로 변환하기
        ```cpp
        class MyString
        {
            ······
            operator char *() const
            {
                char *pt = new char[length() + 1];
                strcpy(pt, buf);
                return pt;
            }
        };
        ```

### **# 값을 제공받는 수신 측 클래스에서 정의하는 방법**
    - 송신 측 클래스의 객체를 인수로 갖는 1 인수 생성자를 정의함
        - 예 : MyString(const char* str);
    - 문제점 : 송신 측 클래스의 private 멤버를 액세스해야 변환이 가능한 경우
        - 변환 대상 송신 측 클래스의 private 멤버를 액세스할 수 있는  멤버함수가 송신 측 클래스에 정의되어 있어야 함

```cpp
class Meter
{
    int m;
    int cm;

public:
    ······
    int getM() const
    {
        return m;
    }
    int getCM() const
    {
        return cm;
    }
};

class Feet
{
    int ft;
    int in;

public:
    ······
    Feet(const Meter &m)
    {
        int cmeter = m.getM() * 100 + m.getCM();
        in = static_cast<int>(cmeter / 2.54 + 0.5);
        ft = in / 12;
        in %= 12;
    }
    ······
};
```

- explicit으로 선언된 생성자
    ```cpp
    class MyString {
        ······
        explicit MyString(const char *str); // 생성자
        ······
    };
    ```
    - MyString str;
    
        str = "Programming"; // 에러
    - ① str = MyString{ "Programming" };
    - ② str = static_cast<MyString>("Programming");
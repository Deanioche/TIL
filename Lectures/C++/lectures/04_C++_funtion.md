# **04_C++_funtion**

## **목차**

1. 함수의 정의와 호출
2. 인수의 전달
3. 함수의 다중정의
4. inline 함수
___

## **1. 함수의 정의와 호출**

- **분산을 구하는 함수**
    [code_link](examples/variance.cpp)

- **화씨 -> 섭씨**
    [code_link](examples/ConvFtoC.cpp)
    ```cpp
    #include <iostream>
    using namespace std;
    // 화씨온도를 섭씨온도로 변환하는 함수
    // 매개변수 float fahr : 화씨온도
    // 반환값 섭씨온도(float)
    float FahrToC(float fahr); // 함수의 원형

    int main()
    {
        float fTemp, cTemp;
        cout << "화씨온도 : ";
        cin >> fTemp;
        cTemp = FahrToC(fTemp); // 함수 호출
        cout << "---> 섭씨온도 : " << cTemp << endl;
        return 0;
    }

    float FahrToC(float fahr)
    {
        return (fahr - 32) * 5 / 9;
    }
    ```

___

## **인수의 전달**

### **값 호출(call by value)**

- 실 매개변수와 형식 매개변수는 별개의 데이터이므로 불필요한 부작용이 발생하지 않음

- 구조체와 같이 많은 양의 데이터로 구성된 인수를 전달할 경우 데이터의 복사량이 많아짐

![image](https://user-images.githubusercontent.com/66513003/140651924-b7bb8db3-fbab-4b7e-a113-e494130d938f.png)


### **참조 호출(call-by-reference)**

- 실 매개변수의 참조를 형식 매개변수에 전달
- 함수에서 형식 매개변수의 값을 변경하는 것은 실 매개변수의 값을 변경하는 것과 같음
- 형식 매개변수에 복사되는 데이터의 양은 실 매개변수의 크기와 관계 없이 일정함
    - 많은 양의 데이터로 구성되는 구조체나 객체를 인수로 전달하는 경우 효율적임

[code_link](examples/SwapInt.cpp)
```cpp
#include <iostream>
using namespace std;
void SwapValues(int &x, int &y); // 원형
int main()
{
    int a, b;
    cout << "두 수를 입력하시오 : ";
    cin >> a >> b;
    if (a < b)
        SwapValues(a, b); // 순서를 바꿔 a에 큰 값을 넣음
    cout << "큰 수 = " << a << " 작은 수 = " << b << endl;
    return 0;
}

void SwapValues(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
```

- 함수 호출의 효율성을 위해 참조 호출을 하지만 실 매개변수의 값이 변경되는 것을 원하지 않는 형식 매개변수에는 **const**를 한정어를 지정하여 실 매개변수를 보호


## **얼라인먼트**
- 구조체를 생성할 때, 32바이트 단위로 맞춰주는게 메모리를 효율적으로 사용할수 있다. 이를 얼라인먼트라 한다.
데이터가 62바이트이더라도 64바이트 블럭을 모두 사용할 수 있어, 메모리가 낭비될 수 있음.

## **const 한정어를 이용한 실 매개변수 보호**

![image](https://user-images.githubusercontent.com/66513003/140652211-55a3b956-00a1-4b26-a316-60a0f7df840d.png)

## **디폴트 인수**

- 디폴트 인수는 인수 중 끝에만 위치할 수 있음
    ![image](https://user-images.githubusercontent.com/66513003/140652431-6624d094-9a07-4d0b-85ff-1adf83f673f9.png)

___

## **3. 함수의 다중정의**

- AddTime() 함수의 다중정의
    ![image](https://user-images.githubusercontent.com/66513003/140652538-a61fd6db-1fb9-4bb6-9ed7-457e1b67d334.png)

[code_link](examples/TimeCalc.cpp)
```cpp
#include <iostream>

using namespace std;

struct TimeRec
{
    int hours;
    int minutes;
};

// 시간을 더하는 함수
// 인수 TimeRec &t1 : 누계할 시간
// const TimeRec &t2 : 더할 시간
// 반환값 없음
void AddTime(TimeRec &t1, const TimeRec &t2)
{
    t1.minutes += t2.minutes;
    t1.hours += t2.hours + t1.minutes / 60;
    t1.minutes %= 60;
}

void AddTime(TimeRec &t, int minutes)
{
    t.minutes += minutes;
    t.hours += t.minutes / 60;
    t.minutes %= 60;
}

int main()
{
    TimeRec tRec1 = {2, 30};
    TimeRec tRec2 = {1, 45};
    cout << tRec1.hours << "시간 " << tRec1.minutes << "분 + ";
    cout << tRec2.hours << "시간 " << tRec2.minutes << "분 = ";
    AddTime(tRec1, tRec2);
    cout << tRec1.hours << "시간 " << tRec1.minutes << "분" << endl;
    cout << tRec1.hours << "시간 " << tRec1.minutes << "분 + ";
    cout << "135분 = ";
    AddTime(tRec1, 135);
    cout << tRec1.hours << "시간 " << tRec1.minutes << "분" << endl;
    return 0;
}
```

- 모호한 함수 다중정의

![image](https://user-images.githubusercontent.com/66513003/140652657-ef8e2224-65de-4f77-b046-0d5fcafc6b76.png)

![image](https://user-images.githubusercontent.com/66513003/140652669-20d956f8-8145-418b-9bfb-62786a791d1a.png)

![image](https://user-images.githubusercontent.com/66513003/140652674-3181ce7e-aed5-4d4f-a4ff-ac2ab5cbc7b5.png)

___

## **4. inline 함수**

- 함수 호출 절차를 따르지 않고 함수 호출 위치에 함수의 처리 **문장이 삽입**되게 번역하도록 선언된 함수
- 함수를 사용함으로써 얻을 수 있는 모듈화의 장점을 살리면서, 함수 호출에 따른 **부수적인 처리시간이 생략**됨
- 함수 호출 루틴으로부터 함수로 넘어가는 부분의 코드 최적화가 가능해짐
    - 매우 빈번히 호출되며 빠른 실행이 요구되는 함수를 inline 함수로 선언하면 **성능을 높이는데** 도움이 됨

### **inline 함수로 선언하더라도 반드시 inline으로 번역되는 것은 아님**

- inline 선언을 무시하고 일반 함수로 번역하는 경우
    - 함수가 너무 큰 경우
    - 순환 호출(recursive call)을 하는 경우
    - 프로그램 내에서 그 함수에 대한 포인터를 사용하는 경우

```cpp
inline void SwapValues(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a, b;
    cout << "두 수를 입력하시오 : ";
    cin >> a >> b;
    if (a < b)
        SwapValues(a, b); // 순서를 바꿔 a에 큰 값을 넣음
    cout << "큰 수 = " << a << " 작은 수 = " << b << endl;
    return 0;
}
```
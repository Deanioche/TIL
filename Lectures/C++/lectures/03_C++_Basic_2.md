# C++_Basic_2 memo

## **학습목표**

흐름제어 구문을 이용하여 구현하고자 하는 논리에 맞게 문장의 흐름제어를 할 수 있다.

구조체와 클래스의 차이점을 설명할 수 있다.

배열을 이용하여 여러 개의 데이터 집합에 대해 반복적 처리를 할 수 있다.

메모리를 필요한 시기에 필요한 만큼 동적으로 할당하거나 반환할 수 있으며, 이처럼 동적으로 할당된 메모리 공간을 포인터를 이용하여 액세스할 수 있다.

l-value 참조 변수와 관련한 문법을 활용할 수 있다.

___

## **목차**
1. 흐름제어 구문
1. 구조체 및 클래스
1. 동적 메모리 할당
1. 참조

___

## **1. 흐름제어 구문**

- 범위 기반 for 루프 (C++ 11)
    ```cpp
    #include <iostream>
    using namespace std;

    int main(int argc, char const *argv[])
    {
        int arr[5] = {2, 3, 9, 4, 7};
        int sum = 0;

        for (int a : arr) // arr의 원소 하나씩 받아옴
            sum += a;

        cout << "sum : " << sum << endl; // 25
        return 0;
    }
    ```
- arr 원소를 참조를 이용해 1씩 늘리기
    ```cpp
    #include <iostream>
    using namespace std;

    int main(int argc, char const *argv[])
    {
        int arr[5] = {1, 2, 3, 4, 5};
        int sum = 0;

        for (int &a : arr)
            a++;

        cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << endl; // 23456
        return 0;
    }
    ```

___

## **2. 구조체와 클래스**

- 구조체
    [code link](examples/Circle.cpp)

- 클래스
    - init : 원의 초기화
    - area : 원의 면적을 계산
    - chkOverlap : 다른 원과 중첩 여부 검사
    - display : 원의 정보 디스플레이
    - center : 중심 좌표
    - radius : 반경
    [code link](examples/Circle_2.cpp)

![image](https://user-images.githubusercontent.com/66513003/140287817-42f216ee-8c93-4427-aac4-d1ab0f3360fe.png)

___

## **3. 동적 메모리 할당**

- 메모리 할당
    ```cpp
    ptrVar = new int;
    ptrVar = new int[n];
    ```
- 메모리 반납
    ```cpp
    delete ptrVar;
    delete [] ptrVar;
    ```

- 배열 데이터 공간 할당 & 반환
    ```cpp
    int *intPtr;
    intPtr = new int[4];
    *intPtr = 10;
    *(intPtr+1) = 20;
    intPtr[2] = 30;

    delete [] intPtr;
    intPtr = nullptr;
    ```

___

## **4. 참조**

### **# l-value 참조**

- 어떠한 대상을 가리키는 값(포인터와 유사함)
- 참조 변수는 참조 대상의 별명처럼 사용할 수 있음
- l-value 참조 : 실체가 있는 대상(l-value)에 대한 참조

- l-value 참조 변수의 선언 형식
    ```
    TypeName &refVar = varName;
    ```
    - TypeName : 참조 대상의 자료형
    - refVar : 참조 변수의 이름
    - varName : 참조 대상

- l-value 참조 변수의 사용 예

    ![image](https://user-images.githubusercontent.com/66513003/140379761-798f7b87-dd5c-4f79-9981-658acd463640.png)

- **const 참조**

    참조를 이용하여 참조 대상의 값을 바꿀 수 없음
    ```cpp
    int x { 10 };
    const int &xRef = x;
    cout << xRef << endl; // x의 값을 읽어 출력함
    xRef += 10; // 오류: const 참조로 값을 수정할 수 없음
    ```

- 참조 변수가 포인터와 다른 점
    - 참조 변수를 이용하여 값을 읽거나 저장할 때 일반 변수를 사용하는 형식과 동일함
    - 참조 변수는 초기화를 통해 반드시 어떤 대상을 참조해야 함
        - 아무것도 참조하지 않는 상황은 발생하지 않음
    - 참조 변수는 초기화를 통해 지정된 참조 대상을 바꿀 수 없어 참조의 유효기간 동안 **하나의 대상**만 참조할 수 있음

#

### **# r-value 참조**

- 사용한 후에는 그 값을 더 이상 가지고 있을 **필요가 없는** 대상을 참조.

- 객체의 값을 다른 객체로 이동하기 위한 용도.

___
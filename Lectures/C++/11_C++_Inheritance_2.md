# **C++ Inheritance 2**

## **목차**
1. 상속과 포인터
2. 가상함수
3. 심화 학습

___

## **1. 상속과 포인터**

![image](https://user-images.githubusercontent.com/66513003/143824212-41385be8-fe9a-42c5-b9cb-a63445327965.png)

- 포인터 (참조)로 가리킬수 있는 대상.
```cpp
int main()
{
    Person *pPrsn1, *pPrsn2;
    Person dudley("Dudley");
    Student *pStdnt;
    Student harry("Harry", "Hogwarts");
    pPrsn1 = &dudley; // OK
    pPrsn2 = &harry; // OK
    pStdnt = &dudley; // Error!
    ······
    return 0;
}
```

### **# 객체 포인터 배열**

[Person.h](examples\ex11\Person.h)
[Student.h](examples\ex11\Student.h)
[PArrMain.cpp](examples\ex11\PArrMain.cpp)

**# 출력 결과**
```cpp
Dudley
Harry goes to Hogwarts

Dudley
Harry
Ron
```

___

**2. 가상함수**

### **# 객체 포인터와 재정의된 멤버함수 호출**

![image](https://user-images.githubusercontent.com/66513003/143850369-8f5812e5-352b-46db-a454-2b26ed685e26.png)

- dudley는 Person의 객체.
- Student객체에는 getSchool()이라는 함수가 있는데 Person의 객체인 dudley에는 존재하지 않으므로 Student *sPt에 &dudley를 받을 수 없다.

![image](https://user-images.githubusercontent.com/66513003/143887145-6ece3167-ec34-4012-8e50-c0be122babb9.png)
![image](https://user-images.githubusercontent.com/66513003/143887606-253e258f-a0f0-4e6f-a7aa-78ba33accc93.png)

- `Person *pPt = &harry;` 에서 `*pPt->print();`는 Harry 만 출력.
- `Student *sPt = &harry;` 에서 `sPt->print();`는 "Harry goes to Hogwarts"를 출력.
- 이렇게 같은 객체를 참조해도 객체 데이터가 담아지정적 연결 (static binding)이라 한다.

```cpp
#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;
int main()
{
    Person *p1 = new Person("Dudley");
    p1->print(); // Dudley, Person::print() 호출
    cout << endl;
    Person *p2 = new Student("Harry", "Hogwarts");
    p2->print();
    cout << endl;             // Harry, Person::print() 호출
    ((Student *)p2)->print(); // Harry goes to Hogwarts, Student::print() 호출
    // p2가 Student 객체를 가리키고 있다는 보장이 없다.
    cout << endl;
    return 0;
}
```
**# 출력 결과**
```
Dudley
Harry
Harry goes to Hogwarts
```

### **# 동적 연결(dynamic binding)**

- 객체 포인터를 통해 객체의 멤버함수를 호출할 경우 포인터가 가리키는 `실제 객체`가 무엇인가에 따라 `실행 중에 멤버함수를 결정`하는 것

- C++에서는 `가상함수(virtual function)`로 동적 연결을 구현함

- 기초 클래스에서 가상함수로 선언한 멤버함수를 재정의한 파생 클래스의 함수는 역시 가상함수이며, 동적 연결이 적용됨

- 정적 연결로 컴파일하여 동작하는 객체
    ![image](https://user-images.githubusercontent.com/66513003/143889229-6eed007b-9492-4f86-bcf3-9bc7a4fbfbe4.png)

- 동적 연결로 동작하는 객체
    ![image](https://user-images.githubusercontent.com/66513003/143889329-4b8a1685-e550-474f-8891-954488ee5bd6.png)
    - virtual 키워드를 선언하면 가상함수가 된다.
    - 그러면 Student 클래스 안의 `void print() const`도 virtual 상태가 됨.
    - vfptr에는 가상함수에 대한 포인터 주소가 담김.
    - 가상함수가 여러개일수 있기 때문에 가리키는 주소는 바뀔 수 있다.

**Person.h**
```cpp
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class Person
{
    string name;

public:
    Person(const string &n) : name(n) {}
    string getName() const { return name; }
    virtual void print() const { cout << name; }
};
#endif // PERSON_H_INCLUDED
```
- `virtual void print() const { cout << name; }`
- print()를 가상함수로 만든다.

**Student.h**
```cpp
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
class Student : public Person
{
    string school;

public:
    Student(const string &n, const string &s) : Person(n), school(s) {}
    string getSchool() const { return school; }
    void print() const
    {
        Person::print();
        cout << " goes to " << school;
    }
};

#endif // STUDENT_H_INCLUDED
```

**PArrMain.cpp**

```cpp
#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;
void PrintPerson(const Person *const p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i]->print(); // -> #1
        cout << endl;
    }
}
int main()
{
    Person dudley("Dudley");
    Student harry("Harry", "Hogwarts");
    Student ron("Ron", "Hogwarts");
    dudley.print();
    cout << endl;
    harry.print();
    cout << endl << endl;
    Person *pPerson[3];
    pPerson[0] = &dudley; //Dudley
    pPerson[1] = &harry;  //Harry goes to Hogwarts
    pPerson[2] = &ron;    //Ron goes to Hogwarts
    PrintPerson(pPerson, 3);
    return 0;
}
```
#### **#1**
- p[i]가 가리키는게 Person 객체일수도 Student일수도 있으므로
객체에 연결된 포인터를 따라가서 연결되어 있는 함수를 호출한다.
- p[0]에서는 dudley객체를 따라가는데, dudley는 Person 객체이므로 Person의 print()를 호출. 
- p[1]과 p[2]에 담긴 harry, ron은 Student 객체이므로 Student의 print()를 호출. 

**# 출력 결과**
```
Dudley
Harry goes to Hogwarts

Dudley
Harry goes to Hogwarts
Ron goes to Hogwarts
```

- 동적 연결은 정적보다는 약간의 성능 저하가 있음. (포인터를 따라가서 객체를 구분해야 하므로)

## **# 소멸자의 동적 연결**

- 소멸자를 가상함수로 선언하지 않는다면?
    - 기초 클래스의 포인터에 연결된 파생 클래스 객체를 제거할 때 기초 클래스의 소멸자만 동작함
    - 파생 클래스의 소멸자가 동작하지 않아 필요한 작업이 누락됨
- 소멸자를 가상함수로 선언
    - 기초 클래스의 포인터에 연결된 파생 클래스 객체를 제거할 때 파생 클래스의 소멸자가 동작할 수 있게 함

### **# 소멸자를 가상함수로 선언하지 않은 경우**

![image](https://user-images.githubusercontent.com/66513003/143893197-e9fb7a28-11b7-4d6c-b4aa-aa0c51201295.png)

### **# 소멸자를 가상함수로 선언한 경우**

![image](https://user-images.githubusercontent.com/66513003/143893284-762c2004-3fbb-4d1b-9e82-392f4214c538.png)

- 함수의 동적 연결과 마찬가지로, 부모 클래스와 자식 클래스의 소멸자를 구분하기 위해 부모 클래스의 소멸자에 virtual 키워드를 입력한다.
- 객체 delete시 해당하는 클래스를 따라가 소멸자 실행.

### **# 업 캐스팅과 다운 캐스팅**

- **업 캐스팅(upcasting)**
    - 파생 클래스 포인터를 기초 클래스 포인터로 변환하는 것
    - 묵시적 형 변환을 통해 업 캐스팅을 할 수 있음

- **다운 캐스팅(downcasting)**
    - 기초 클래스 포인터를 파생 클래스 포인터로 변환하는 것
    - 묵시적 형 변환을 할 수 없으며, 형 변환 연산자로 명시적 형 변환을 해야 함

![image](https://user-images.githubusercontent.com/66513003/143893905-618d3134-d084-49d3-b9cf-3011b6b56bf4.png)

### **# static_cast 연산자를 사용한 `명시적` 다운 캐스팅**

![image](https://user-images.githubusercontent.com/66513003/143894755-fc1d6bf0-af4a-4374-bd44-3e3d73014f3a.png)

- Person 클래스의 포인터인 pPrsn2가 Student 클래스의 객체를 가리키고 있었기 때문에 정상적인 동작을 함

- pPrsn2가 Student 클래스의 객체를 가리키고 있다는 것을 `명확하게 알고 있을 때만` 사용해야 한다!!

- 따라서 static_cast를 이용한 다운캐스팅은 항상 올바른 동작이 될 것이란 보장이 없으므로 객체를 확인해 `동적으로` casting을 할 필요가 있음.

### **# dynamic_cast 연산자를 사용한 동적 다운 캐스팅**

![image](https://user-images.githubusercontent.com/66513003/143895914-4fd5fff4-2748-4492-8be0-aebfb0dbd881.png)

- dynamic_cast는 pPrsn1이 Student 객체를 가리키고 있지 않기 때문에 nullptr를 반환함

![image](https://user-images.githubusercontent.com/66513003/143895990-b425c582-f2af-4cd6-a51e-8982b8795eeb.png)

- pPrsn2가 Student 객체를 가리키고 있으므로 dynamic_cast로 정상적인 다운 캐스팅이 됨
- dynamic_cast를 사용하려면 클래스 선언문에 가상함수를 포함하고 있어야 함

___

## **3. 심화 학습**

### **# 가상함수의 재정의 (override)**

- virtual은 기초 클래스의 가상함수를 재정의할 때는 지정할 필요가 없으며, 파생 클래스에서 새롭게 가상함수를 선언하고자 할 때만 사용하는 것이 좋음
- 파생 클래스에서 어떤 함수가 가상함수인지 명확히 알기 어려울 수 있으므로, 가상함수를 재정의함을 명시적으로 알리고자 할 때는 ‘override’를 지정함

![image](https://user-images.githubusercontent.com/66513003/143896242-5448b0ba-8aba-4224-92c6-7d4695a45fce.png)

- 가상함수의 재정의 금지
    - 가상함수를 더 이상 재정의하지 못하게 하려면 ‘final’을 지정함

    ![image](https://user-images.githubusercontent.com/66513003/143896324-a9e81f4d-a496-4a6f-9b91-a41270d8d7fd.png)
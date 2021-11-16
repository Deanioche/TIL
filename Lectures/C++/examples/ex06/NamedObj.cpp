#include <cstring>
#include <iostream>
#include "NamedObj.h"
using namespace std;

NamedObj::NamedObj(const char *s) // NamedObj의 멤버인 생성자 static으로 선언
{
    name = new char[strlen(s) + 1]; // 문자열을 복사할 공간을 할당
    strcpy(name, s);
    id = ++nConstr; // 생성된 객체의 수를 증가시키고 이를 ID로 부여
}
NamedObj::~NamedObj() // NamedObj의 멤버인 소멸자 static으로 선언
{
    ++nDestr; // 소멸된 객체의 수를 증가시킴
    delete[] name;
}

// static 데이터 멤버의 정의 및 초기화
int NamedObj::nConstr = 0;
int NamedObj::nDestr = 0;
// 이 두 문장이 없으면 컴파일시 에러가 발생

void f()
{
    NamedObj x("Third"); // 세 번째 객체의 생성
    x.display();         // ID : 3 --> 이름 : Third
    // 함수 종료시 x는 소멸됨
}
int main()
{
    cout << "NamedObj 클래스의 객체 수 : " // NamedObj 클래스의 객체 수 : 0
         << NamedObj::nObj() << endl;
    NamedObj a("First");  // 첫 번째 객체 생성
    NamedObj b("Second"); // 두 번째 객체 생성
    f();
    NamedObj c("Fourth"); // 네 번째 객체 생성
    c.display();          // ID : 4 --> 이름 : Fourth
    cout << "NamedObj 클래스의 객체 수 : "
         << NamedObj::nObj() << endl; // NamedObj 클래스의 객체 수 : 3
    return 0;
}
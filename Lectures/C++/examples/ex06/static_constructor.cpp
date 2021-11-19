#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class n
{
    char *name;
    int id;
    static int nConstr; // 생성된 객체 수
    static int nDestr;  // 소멸된 객체 수
public:
    n();              // 생성자
    n(const char *c); // 생성자
    ~n();             // 소멸자
    void d() const    // const 이므로 d()는 재선언 할 수 없음.
    {                 // 객체의 속성 출력
        cout << "ID : " << id << " --> 이름 : " << name << endl;
    }
    static int num()
    { // 존재하는 객체 수 반환
        return nConstr - nDestr;
    }
};

n::n()
{
    printf("static 생성자 호출");
}
n::n(const char *c)
{
    printf("static 생성자 + 값 지정");
    name = new char[strlen(c) + 1]; // 문자열을 복사할 공간을 할당
    strcpy(name, c);
    id = ++nConstr; // 생성된 객체의 수를 증가시키고 이를 ID로 부여
}
n::~n()
{
    printf("static 소멸자 호출");
}

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

    return (0);
}

#include <iostream>
#include <cstring>
#include "Person.h"
using namespace std;

Person::Person(const char *name, const char *addr)
{
    // 이름을 저장할 공간 할당
    this->name = new char[strlen(name) + 1];
    // 데이터 멤버 name에 이름을 복사
    strcpy(this->name, name);
    // 주소를 저장할 공간 할당
    this->addr = new char[strlen(addr) + 1];
    // 데이터 멤버 addr에 주소를 복사
    strcpy(this->addr, addr);
    cout << "Person 객체 생성함(" << name << ")" << endl;
}
Person::~Person() // 소멸자
{
    cout << "Person 객체 제거함(" << name << ")" << endl;
    delete[] name; // 이름 저장공간 반납
    delete[] addr; // 주소 저장공간 반납
}
void Person::print() const
{
    cout << addr << "에 사는 " << name << "입니다." << endl;
}
void Person::chAddr(const char *newAddr)
{
    delete[] addr; // 기존 공간 반납
    // 새로운 주소에 맞는 공간 할당
    addr = new char[strlen(newAddr) + 1];
    strcpy(addr, newAddr); // 데이터멤버 addr에 새로운 주소를 복사
}

int main()
{
    Person *p1 = new Person("이철수", "서울시 종로구");
    Person *p2 = new Person("박은미", "강원도 동해시");
    p1->print();
    p2->print();
    cout << endl
         << "주소 변경 : ";
    p2->chAddr("대전시 서구");
    p2->print();
    delete p1;
    delete p2;
    return 0;
}
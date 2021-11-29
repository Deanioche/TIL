#include <iostream>
#include "1_Person.h"
#include "1_Student.h"
using namespace std;
int main()
{
    Person dudley;               // 기초 클래스의 객체 선언
    dudley.setName("Dudley");    // 기초 클래스의 함수 호출
    Student harry;               // 파생 클래스의 객체 선언
    harry.setName("Harry");      // 기초 클래스의 함수 호출
    harry.setSchool("Hogwarts"); // 파생 클래스의 함수 호출
    dudley.print();              // 기초 클래스의 함수 호출
    cout << endl;
    harry.print(); // 파생 클래스의 함수 호출
    cout << endl;
    harry.Person::print(); // 기초 클래스의 함수 호출
    cout << endl;
    return 0;
}

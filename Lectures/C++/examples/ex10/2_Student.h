#include <iostream>
#include "2_Person.h"

// 파생 클래스 Student를 Person을 상속받아 선언함
class Student : public Person
{
    string school;

public:
    Student(const string &n, const string &s) : Person(n)
    {
        cout << "Student의 생성자" << endl;
        school = s;
    }
    ~Student()
    {
        cout << "Student의 소멸자" << endl;
    }
    void setSchool(string s) { school = s; }
    string getSchool() const { return school; }
    void print() const
    {
        Person::print();
        cout << " goes to " << school;
    }
};
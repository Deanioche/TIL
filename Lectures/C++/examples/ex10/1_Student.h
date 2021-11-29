#include <iostream>
#include "1_Person.h"

// 파생 클래스 Student를 Person을 상속받아 선언함
class Student : public Person
{
    string school;

public:
    void setSchool(string s) { school = s; }
    string getSchool() const { return school; }
    void print() const
    {
        Person::print();
        cout << " goes to " << school;
    }
};
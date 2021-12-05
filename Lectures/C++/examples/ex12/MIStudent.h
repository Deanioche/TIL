#ifndef MISTUDENT_H_INCLUDED
#define MISTUDENT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class Student
{
    string school;

public:
    Student(const string &s) : school(s) {}
    void printSchool() const { cout << school << endl; }
};
#endif // MISTUDENT_H_INCLUDED
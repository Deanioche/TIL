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

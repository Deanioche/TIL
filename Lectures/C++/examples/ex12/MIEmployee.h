#ifndef MIEMPLOYEE_H_INCLUDED
#define MIEMPLOYEE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class Employee
{
    string company;

public:
    Employee(const string &c) : company(c) {}
    void printCompany() const { cout << company << endl; }
};
#endif // MIEMPLOYEE_H_INCLUDED
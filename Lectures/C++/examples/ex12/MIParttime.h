#ifndef MIPARTTIME_H_INCLUDED
#define MIPARTTIME_H_INCLUDED
#include <string>
#include "MIStudent.h"
#include "MIEmployee.h"
using namespace std;
// Student와 Employee를 모두 상속받음
class Parttime : public Student, public Employee
{
public:
    Parttime(const string &s, const string &c)
        : Student(s), Employee(c) {}
};
#endif // MIPARTTIME_H_INCLUDED
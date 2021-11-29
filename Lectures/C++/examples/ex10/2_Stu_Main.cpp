#include <iostream>
#include "2_Person.h"
#include "2_Student.h"
using namespace std;
int main()
{
    Student harry("Harry", "Hogwarts");
    cout << harry.getName() << " goes to "
         << harry.getSchool() << endl;
    return 0;
}

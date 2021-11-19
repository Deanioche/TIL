#include <iostream>
#include "Complex1.h"
using namespace std;
Complex1 Complex1::mul(const Complex1 &c) const
{
    double r = rPart * c.rPart - iPart * c.iPart;
    double i = rPart * c.iPart + iPart * c.rPart;
    return Complex1(r, i);
}
Complex1 Complex1::div(const Complex1 &c) const
{
    double d = c.rPart * c.rPart + c.iPart * c.iPart;
    Complex1 c1 = mul(c.conj());
    return Complex1(c1.rPart / d, c1.iPart / d);
}
void Complex1::display() const
{
    cout << "(" << rPart;
    if (iPart > 0)
        cout << "+j" << iPart;
    else if (iPart < 0)
        cout << "-j" << -iPart;
    cout << ")";
}

int main()
{
    Complex1 c1(1, 2);
    Complex1 c2(2, 3);
    Complex1 c3 = c1.add(c2);
    c1.display();
    cout << " + ";
    c2.display();
    cout << " = ";
    c3 = c1.mul(10.0);
    c1.display();
    cout << " * 10 = ";
    c3.display();
    cout << endl;
    return 0;
}
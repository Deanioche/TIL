#include <iostream>

using namespace std; // namespace 사용 선언
namespace myNSp1
{
    int n = 10;
}
namespace myNSp2
{
    int n = 20;
}
int n = 30;

int main()
{
    int n = 40;
    cout << myNSp1::n << endl;
    cout << myNSp2::n << endl;
    cout << ::n << endl;
    cout << n << endl;
    return 0;
}
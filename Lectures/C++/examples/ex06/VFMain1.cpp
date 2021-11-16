#include <iostream>
using namespace std;
#include "VecF.h"
int main()
{
    float a[3] = {1, 2, 3};
    VecF v1(3, a); // 1, 2, 3을 저장하는 벡터
    VecF v2{v1};   // v1을 복사
    v1.print();
    cout << endl; // [ 1 2 3 ]
    v2.print();
    cout << endl; // [ 1 2 3 ]

    VecF t = v1.add(v2);
    v1 = t;
    v1.print(); // [ 2 4 6 ]

    v1 = v1.add(v2); // v1을 참조하며 v1 객체를 수정 -> 깨짐.
    v1.print();      // [ 2.38953e-038 2.38778e-038 9 ]

    return 0;
}

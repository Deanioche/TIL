#include <iostream>
#include "SafeIntArray.h"
using namespace std;
int main()
{
    SafeIntArray a(10); // 10개의 원소를 갖는 객체 생성
    for (int i = 0; i < 10; i++)
        a[i] = i;
    cout << a[5] << endl;  // 올바른 범위의 원소 액세스
    cout << a[12] << endl; // 범위를 벗어난 액세스
    return 0;
}

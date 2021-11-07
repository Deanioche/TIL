#include <iostream>
using namespace std;
// 화씨온도를 섭씨온도로 변환하는 함수
// 매개변수 float fahr : 화씨온도
// 반환값 섭씨온도(float)
float FahrToC(float fahr); // 함수의 원형

int main()
{
    float fTemp, cTemp;
    cout << "화씨온도 : ";
    cin >> fTemp;
    cTemp = FahrToC(fTemp); // 함수 호출
    cout << "---> 섭씨온도 : " << cTemp << endl;
    return 0;
}

float FahrToC(float fahr)
{
    return (fahr - 32) * 5 / 9;
}
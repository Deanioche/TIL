#include <iostream>
#include "MyString.cpp"
using namespace std;

int main()
{
    MyString str1("MyString class");
    MyString str2("Object Oriented ");
    MyString str3;
    cout << str1 << endl; // 문자열 출력
    str3 = "Programming"; // 묵시적 형 변환 및 이동 대입
    cout << str3 << "의 문자열 길이는 ";
    cout << str3.length() << endl; // 문자열 길이를 구하는 메소드
    str1 = str2;                   // 대입 연산자로 문자열 복사
    cout << str1 << endl;
    str1 = str2 + str3; // 문자열 연결 연산자, 이동 대입 연산자
}

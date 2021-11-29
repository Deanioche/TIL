#include <iostream>
using namespace std;

int main()
{
    cout << "202134-363777 이도현" << endl;

    char *sPtr;
    int maxSLen;
    cout << "단어의 최대 길이를 입력하시오 : ";
    cin >> maxSLen; // 문자열 입력해 maxSLen에 담기.

    sPtr = new char[maxSLen + 1]; // maxSLen개의 문자를 저장할 메모리 할당. +1은 NULL
    cout << "단어를 입력하시오 : ";
    cin >> sPtr;
    for (char *p = sPtr; (*p); p++) // *p를 이용하여 모든 문자 처리
        if (*p >= 97 && *p <= 122)
            (*p) -= 32; // 소문자를 대문자로 변환

    // if문 대신 이거도 가능
    // *p += ('a' <= *p && *p <= 'z') * ('A' - 'a');
    // 앞 괄호가 참이면 1 거짓이면 0을 반환하므로

    cout << sPtr << endl;
    delete[] sPtr; // 앞에서 할당한 메모리 반환
}
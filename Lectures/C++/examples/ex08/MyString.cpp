#include <iostream>
#include <cstring>
#include "MyString.h"
MyString::MyString(int s) : len(s), bufSize(s)
{
    buf = new char[s + 1];
    buf[s] = '\0';
}
MyString::MyString() : len(0), bufSize(0) // 디폴트 생성자
{
    buf = new char[1];
    buf[0] = '\0';
}
MyString::MyString(const char *str) // 생성자
{
    len = bufSize = strlen(str); // 문자열 길이
    buf = new char[len + 1];     // 문자열 저장공간 할당
    strcpy(buf, str);            // 문자열 복사
}
MyString::MyString(const MyString &mstr) // 복사 생성자
    : len(mstr.len), bufSize(mstr.len)
{
    buf = new char[len + 1];
    strcpy(buf, mstr.buf);
}
MyString::MyString(MyString &&mstr) // 이동 생성자
    : len(mstr.len), bufSize(mstr.bufSize), buf(mstr.buf)
{
    mstr.buf = nullptr;
}
MyString::~MyString() // 소멸자
{
    delete[] buf;
}
int MyString::length() const // 문자열 길이 반환 메소드
{
    return len;
}
MyString &MyString::operator=(const MyString &mstr)
{
    if (bufSize < mstr.len)
    {                             // 문자열 공간이 필요량보다 작으면
        delete[] buf;             // 기존 공간 반환
        len = bufSize = mstr.len; // 새로운 문자열의 길이
        buf = new char[len + 1];  // 새로운 공간 할당
    }
    else                // 그렇지 않으면
        len = mstr.len; // 문자열의 길이만 수정
    strcpy(buf, mstr.buf);
    return *this;
}
/*
char cstr1[10] = "C string";
char cstr2[10];
char *cstr3;
MyString mstr1("MyString 객체");
MyString mstr2;
cstr2 = cstr1; // 에러
cstr3 = cstr1; // 포인터 복사
mstr2 = mstr1; // deep copy
이동 연산자
*/

MyString &MyString::operator=(MyString &&mstr)
{
    delete[] buf;
    len = mstr.len;
    bufSize = mstr.bufSize;
    buf = mstr.buf;
    mstr.buf = nullptr;
    return *this;
}
// 문자열 연결 연산자
MyString MyString::operator+(const MyString &mstr) const
{
    MyString tmstr(len + mstr.len); // private으로 정의한 생성자
    strcpy(tmstr.buf, buf);
    strcpy(tmstr.buf + len, mstr.buf);
    return tmstr;
}
MyString &MyString::operator+=(const MyString &mstr)
{
    if (bufSize < len + mstr.len)
    {
        char *tbuf = new char[(bufSize = len + mstr.len) + 1];
        strcpy(tbuf, buf);
        delete[] buf;
        buf = tbuf;
    }
    strcpy(buf + len, mstr.buf);
    len += mstr.len;
    return *this;
}

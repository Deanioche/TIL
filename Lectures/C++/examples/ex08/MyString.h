#include <iostream>
#include <ostream>
class MyString
{
    int len;     // 문자열의 길이
    int bufSize; // 저장 가능한 문자열의 길이
    char *buf;
    MyString(int s); // 생성자(private)
public:
    MyString();                     // 디폴트 생성자
    MyString(const char *str);      // 생성자
    MyString(const MyString &mstr); // 복사 생성자
    MyString(MyString &&mstr);      // 이동 생성자
    ~MyString();                    // 소멸자
    int length() const;             // 문자열 길이 반환 메소드
    // 대입 연산자
    MyString &operator=(const MyString &mstr);
    // 이동 연산자
    MyString &operator=(MyString &&mstr);
    // 문자열 연결 연산자
    MyString operator+(const MyString &mstr) const;
    MyString &operator+=(const MyString &mstr);
    bool operator==(const MyString &mstr) const; // == 연산자
    bool operator>(const MyString &mstr) const;  // > 연산자
    bool operator<(const MyString &mstr) const;  // < 연산자
    char &operator[](int i);
    char operator[](int i) const;
    friend std::ostream &operator<<(std::ostream &os, const MyString &mstr);
    // 스트림 출력 연산자
    inline std::ostream &operator<<(std::ostream &os, const MyString &mstr)
    {
        os << mstr.buf;
        return os;
    };
};

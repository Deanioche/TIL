#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
class Person
{                                               // 클래스 Person의 선언 시작
    char *name;                                 // 이름을 저장하는 데이터멤버
    char *addr;                                 // 주소를 저장하는 데이터멤버
public:                                         // public 멤버함수
    Person(const char *name, const char *addr); // 생성자
    ~Person();                                  // 소멸자
    void print() const;                         // 이름과 주소 출력
    void chAddr(const char *newAddr);           // 주소 변경
};
#endif // PERSON_H_INCLUDED
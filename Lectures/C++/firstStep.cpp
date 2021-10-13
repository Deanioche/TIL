#include <iostream>
int main()
{
    int a = 100;
    // 표준 출력 스트림으로 문장을 출력함
    std::cout << "나의 첫 번째 C++ 프로그램\n";
    std::cout << "a의 값은\n"
              << a << "\n입니다."
              << std::ends; // 줄바꿈 x. Null만 입력됨.
    std::cout << "123";     // end를 하지 않아도 출력은 된다.
    return 0;
}
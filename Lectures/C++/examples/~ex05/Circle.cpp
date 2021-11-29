#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141593;

struct C2dType
{ // 2차원 좌표 구조체
    double x, y;
};

struct CircleType
{                   // 원 구조체
    C2dType center; // 중심좌표
    double radius;  // 반경
};

// 부피
double circleArea(CircleType c)
{
    return c.radius * c.radius * PI;
}

// 겹치는지 여부
bool chkOverlap(CircleType c1, CircleType c2)
{
    double dx = c1.center.x - c2.center.x;
    double dy = c1.center.y - c2.center.y;
    double dCntr = sqrt(dx * dx + dy * dy);
    return dCntr < c1.radius + c2.radius;
}

// 정보 출력
void dispCircle(CircleType c)
{
    cout << " 중심 : (" << c.center.x << ", "
         << c.center.y << ")";
    cout << " 반경 : " << c.radius << endl;
}

int main()
{
    // 원 생성 (좌표, 반지름)
    CircleType c1 = {{0, 0}, 10};
    CircleType c2 = {{30, 10}, 5};

    cout << "원1" << endl;
    dispCircle(c1);
    cout << " 원1의 면적 : "
         << circleArea(c1) << endl;
    cout << "원2" << endl;
    dispCircle(c2);

    cout << " 원2의 면적 : "
         << circleArea(c2) << endl
         << endl;

    // 두 원의 중첩 여부 출력
    if (chkOverlap(c1, c2))
        cout << "두 원은 중첩됩니다." << endl;
    else
        cout << "두 원은 중첩되지 않습니다." << endl;
    return 0;
}

/*
원1
 중심 : (0, 0) 반경 : 10
 원1의 면적 : 314.159
원2
 중심 : (30, 10) 반경 : 5
 원2의 면적 : 78.5398

두 원은 중첩되지 않습니다.
*/
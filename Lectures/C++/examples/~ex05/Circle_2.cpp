#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141593;

// 원 클래스
class CircleClass
{
public:
    struct C2dType
    { // 2차원 좌표 구조체
        double x, y;
    };

    C2dType center; // 중심 좌표
    double radius;  // 반경

    void init(double cx, double cy, double r)
    {
        center = {cx, cy};
        radius = r;
    }

    // 원의 면적 계산
    double area() const
    {
        return radius * radius * PI;
    }

    // 겹치는지 여부 계산
    bool chkOverlap(const CircleClass &c) const
    {
        double dx = center.x - c.center.x;
        double dy = center.y - c.center.y;
        double dCntr = sqrt(dx * dx + dy * dy);
        return dCntr < radius + c.radius;
    }

    void display() const
    {
        cout << " 중심 : (" << center.x << ", "
             << center.y << ")";
        cout << " 반경 : " << radius << endl;
    }
};

int main()
{
    CircleClass c1, c2;
    c1.init(0, 0, 10);  // 중심(0,0), 반경10으로 초기화
    c2.init(30, 10, 5); // 중심(30,10), 반경5로 초기화

    cout << "원1" << endl;
    c1.display();
    cout << " 원1의 면적 : " << c1.area() << endl;

    cout << "원2" << endl;
    c2.display();
    cout << " 원2의 면적 : " << c2.area() << endl
         << endl;

    // 두 원의 중첩 여부 출력
    if (c1.chkOverlap(c2))
        cout << "두 원은 중첩됩니다." << endl;
    else
        cout << "두 원은 중첩되지 않습니다." << endl;
    return 0;
}
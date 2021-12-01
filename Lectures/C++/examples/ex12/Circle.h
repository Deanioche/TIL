#include "Figure.h"

class Circle : public Figure
{
    double cx, cy; // 원의 중심 좌표
    double radius; // 원의 반경
public:
    // 현재의 그래픽 속성에 따라 원 객체 생성
    // (x, y) : 중심좌표
    // r : 반경
    Circle(double x, double y, double r)
        : cx(x), cy(y), radius(r) {}
    // 원의 이동, 원점 기준 크기 조정, 그리기 멤버함수
    void move(double dx, double dy);
    void scale(double s);
    void draw() const;
};
#include "Figure.h"

class Triangle : public Figure
{
    // 삼각형의 세 꼭짓점 좌표 (x1, y1), (x2, y2), (x3, y3)
    double x1, y1, x2, y2, x3, y3;

public:
    // 현재의 그래픽 속성에 따라 삼각형 객체 생성
    // v : 세 개의 꼭짓점 좌표 배열
    Triangle(const double v[3][2]);
    // 삼각형의 이동, 원점 기준 크기 조정, 그리기 멤버함수
    void move(double dx, double dy);
    void scale(double s);
    void draw() const;
};
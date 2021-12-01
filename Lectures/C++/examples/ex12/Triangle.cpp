#include "Triangle.h"
#include <iostream>

using namespace std;
// 생성자 : 세 꼭짓점 좌표를 초기화
Triangle::Triangle(const double v[3][2])
{
    x1 = v[0][0];
    y1 = v[0][1];
    x2 = v[1][0];
    y2 = v[1][1];
    x3 = v[2][0];
    y3 = v[2][1];
}
// 세 꼭짓점 좌표를 (dx, dy)만큼 이동
void Triangle::move(double dx, double dy)
{
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
    x3 += dx;
    y3 += dy;
}
// 세 꼭짓점 좌표를 s배 만큼 조정
void Triangle::scale(double s)
{
    x1 *= s;
    y1 *= s;
    x2 *= s;
    y2 *= s;
    x3 *= s;
    y3 *= s;
}
// 삼각형을 그리는 방법 출력
void Triangle::draw() const
{
    cout << "삼각형 그리기" << endl;
    cout << "(" << x1 << ", " << y1 << "), ";
    cout << "(" << x2 << ", " << y2 << "), ";
    cout << "(" << x3 << ", " << y3 << ")의 좌표를 잇는 선분을 ";
    cout << attrib.getLineColor() << "으로 그리고" << endl;
    cout << "내부를 " << attrib.getFillColor();
    cout << "으로 채운다." << endl;
}
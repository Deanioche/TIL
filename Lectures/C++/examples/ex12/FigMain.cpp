#include <iostream>
#include <string>
#include "GrAttrib.h"
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;
// 현재의 그래픽 속성
GrAttrib curAttrib("검정", "흰색");
void drawFigs(const Figure *const figs[], int n)
{
    for (int i = 0; i < n; i++)
    {
        figs[i]->draw();
        cout << endl;
    }
}
int main()
{
    Figure *figs[2];
    figs[0] = new Circle(0, 20, 10);
    double v[3][2] = {{0, 0}, {20, 0}, {10, 15}};
    curAttrib.setLineColor("빨강");
    curAttrib.setFillColor("노랑");
    figs[1] = new Triangle(v);
    drawFigs(figs, 2);    // 모든 도형 그리기 방법 출력
    figs[0]->scale(2);    // 원의 크기 조정
    figs[1]->move(5, 10); // 삼각형의 이동
    drawFigs(figs, 2);    // 모든 도형 그리기 방법 출력
    return 0;
}
# **test_memo**


### const 위치에 따른 의미

아시다시피 'const'의 기본 컨셉은 '해당 값을 변경하지 않는다.' 입니다.

하지만 위치에 따라 그 범위와 가리키는게 약간씩 차이가 있어서 헷갈리기 쉽습니다.
 
```cpp
class Point {
private:
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x{_x}, y{_y} {}
    void Print() const { cout << x << ", " << y << endl; }
    const Point operator+(const Point& rhs) const
    {
    	Point p;
        p.x = this->x + rhs.x;
        p.y = this->y + rhs.y;
        
        return p;
    }	
};
```

1. 함수명 뒤의 'const'가 가지는 의미

해당 함수에서 멤버변수를 읽기전용(RDONLY)으로 사용하겠다는 표시입니다.

즉, '읽기'만 할뿐 '쓰기'는 하지않겠다는 의미입니다.
 
2. 위의 함수 매개변수에서 'const'가 가지는 의미

매개변수에서의 'const' 사용은 다들 익숙하시리라 생각됩니다. 

'call by reference'로 복사 오버헤드없이 참조하는 변수를 마찬가지로 읽기전용(RDONLY)으로 사용하겠다는 표시입니다.

3. 함수 반환타입 앞의 'const'가 가지는 의미

함수의 반환값을 읽기전용(RDONLY)으로 사용하겠다는 표시입니다.

함수가 반환하는 값은 right-hand-side(이하 rhs)에 해당합니다. 여기서 이 값을 '&&'(r-value 참조)로 받아버리면 수정할 여지가 생깁니다. 이러한 가능성을 제거하고 '해당 함수가 반환하는 값은 대입연산자를 통해 복사해서 사용하라'는 의미라 생각됩니다.
___

### vector<>, pair<>, set<>
```cpp
#include <bits/stdc++.h>
using namespace std;
int n, a, b;
set<pair<int, int>> s;
main()
{
    for (cin >> n; n--; s.insert({a, b}))
        scanf("%d %d", &a, &b);
    for (auto i : s)
        printf("%d %d\n", i.first, i.second);
}
```
- set<>은 중복 제거와 정렬을 알아서 해줌
- set 객체에 .insert({a, b})로 pair를 만들어 넣을 수 있다.
- for (auto i : s)로 s객체의 원소들을 하나씩 출력 가능

```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        printf("%d %d\n", v[i].first, v[i].second);
}
```
- `v.push_back({x, y});` 으로도, `v.push_back(make_pair(x, y));`로도 입력가능.
- 
___

### **복사, 이동 생성자 사용 예시**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class A
{
    int a;

public:
    A(int n) : a{n}
    {
        printf("값 저장됨. a : %d\n", n);
    }
    A(A &v) : a{v.a}
    {
        printf("복사 생성자 호출됨. a : %d\n", v.a);
    }
    A(A &&v) : a{v.a}
    {
        printf("이동 생성자 호출됨. a : %d\n", v.a);
    }
    ~A()
    {
        printf("객체 삭제\n");
    }
    void p()
    {
        printf("프린트 a : %d\n", this->a);
    }
    A r(A a)
    {
        return a;
    }
};

int main()
{
    A a(1);      // 값 저장됨.
    A b(a);      // 복사 생성자 호출됨. a : 1
    A c(b.r(a)); // 복사 생성자 호출됨. a : 1
                 // 이동 생성자 호출됨. a : 1

    c.p(); // 프린트 a : 1

    // 객체 삭제
    // 객체 삭제
    // 객체 삭제
    // 객체 삭제
    return (0);
}
```

___

### **# 동일한 객체로 얕은 복사시 데이터 깨짐**
[ref_link](https://hombody.tistory.com/317)
```cpp
#include <iostream>
using namespace std;
#include "VecF.h"
int main()
{
    float a[3] = {1, 2, 3};
    VecF v1(3, a); // 1, 2, 3을 저장하는 벡터
    VecF v2{v1};   // v1을 복사
    v1.print();
    cout << endl; // [ 1 2 3 ]
    v2.print();
    cout << endl; // [ 1 2 3 ]

    VecF t = v1.add(v2);
    v1 = t;
    v1.print(); // [ 2 4 6 ]

    v1 = v1.add(v2); // v1을 참조하며 v1 객체를 수정 -> 깨짐.
    v1.print();      // [ 2.38953e-038 2.38778e-038 9 ]

    return 0;
}
```

___


```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int *p2;
    int p[] = {1, 2, 3};
    p2 = new int[5];
    memset(p2, 0, sizeof(int) * 5);
    memcpy(p2, p, sizeof(int) * 3);

    while (*p2)
    {
        cout << *(p2++) << endl; // 1 2 3
    }
    return 0;
}
```

#include <stdio.h>

class Object
{
    const int a;
    int b;

public:
    Object(int a) : a(a), b{9} {}
    void p()
    {
        printf("%d ", a);
        printf("%d\n", b);
    }
};

int main()
{
    Object t(10);
    t.p(); // 10 9

    Object t2{t};
    t2.p(); // 10 9

    Object t3 = t2;
    t3.p(); // 10 9

    Object tarr[3]{1, 2, 3};
    tarr[0].p(); // 1 9
    tarr[1].p(); // 2 9
    tarr[2].p(); // 3 9

    Object *tp = new Object[2]{1, 2};
}

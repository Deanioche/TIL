#include <iostream>
#include <cstring>
using namespace std;
class VecF
{
    int n;
    float *arr;

public:
    VecF(int d, const float *a = nullptr) : n{d}
    {
        arr = new float[d];
        if (a)
            memcpy(arr, a, sizeof(float) * n);
        // arr 주소에 a에 담긴 값을 n 길이만큼 복사
    }
    // 복사 생성자 지정
    VecF(const VecF &fv) : n{fv.n}
    {
        arr = new float[n];
        memcpy(arr, fv.arr, sizeof(float) * n);
    }
    ~VecF()
    {
        delete[] arr;
    }
    VecF add(const VecF &fv) const
    {
        VecF tmp = VecF(n); // 벡터의 덧셈 결과를 저장할 임시 객체
        for (int i = 0; i < n; i++)
        {
            tmp.arr[i] = arr[i] + fv.arr[i];
        }
        return tmp; // 덧셈 결과를 반환함
    }
    void print() const
    {
        cout << "[ ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "]";
    }
};
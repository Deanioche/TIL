#include <iostream>
#include <string.h>
using namespace std;

double variance(const double arr[], int n)
{
    double sum = 0, sqSum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sqSum += arr[i] * arr[i];
    }
    return sqSum / n - sum * sum / (n * n);
}

int main()
{
    // a와 b에 각각 50개와 100개의 데이터 입력
    double a[50] = {
        0,
    };
    double b[100] = {
        0,
    };
    cout << variance(a, 50) << endl;
    cout << variance(b, 100) << endl;
}
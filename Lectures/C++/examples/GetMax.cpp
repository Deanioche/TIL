#include <iostream>
using namespace std;

int INT_MIN = -2147483648;

int getMax(int arr[], int len) // 함수 머리부
{
    int max = INT_MIN; // int형의 최솟값을 max로 가정함
    for (int i = 0; i < len; i++)
        if (max < arr[i])
            max = arr[i];

    return (max);
    // 결과의 반환
}

// float형 배열 다중정의
float getMax(float arr[], int len)
{
    float max = INT_MIN;
    for (int i = 0; i < len; i++)
        if (max < arr[i])
            max = arr[i];

    return (max);
}

int main()
{
    cout << "202134-363777 이도현" << endl;

    //int data[10] = {10, 23, 5, 9, 22, 48, 12, 10, 55, 31};
    float data[10] = {10.3, 23.5, 5.7, 9.1, 22.2, 48.8, 12.6, 10.3, 55.2, 31.0};

    cout << "데이터 : ";
    for (int i = 0; i < 10; i++)
        cout << data[i] << "  ";
    cout << endl
         << endl;
    cout << "최댓값 = " << getMax(data, 10) << endl;
}
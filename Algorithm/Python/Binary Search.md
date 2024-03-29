# 이진 탐색 알고리즘 (Binary Search)

**순차 탐색**  
리스트 안에 있는 특정한 데이터를 찾기 위해 앞에서부터 데이터를 하나씩 확인하는 방법

**이진 탐색**  
정렬되어 있는 리스트에서 탐색 범위를 절반씩 좁혀가며 데이터를 탐색하는 방법
이진 탐색은 시작점, 끝점, 중간점을 이용하여 탐색 범위를 설정

!!! **정렬된 데이터를 사용해야 한다**
```py
def binary_search(ary, fData):
    pos =-1
    start = 0
    end = len(ary) - 1

    while (start <= end):
        mid = (start + end) // 2
        if fData == ary[mid]:
            return mid
        elif fData > ary[mid]:
            start = mid + 1
        else:
            end = mid - 1

    return pos

dataAry = [50, 105, 120, 150, 162, 168, 177, 188]
findData = 162

position = binary_search(dataAry, findData)
if position == -1:
    print("없어요")
else:
    print(dataAry[position])
```

**이진 탐색의 시간 복잡도**  
단계마다 탐색 범위를 2로 나누는것과 동일하므로 연산 횟수는 logN에 비례한다
다시 말해 이진 탐색은 탐색 범위를 절반씩 줄이며, 시간 복잡도는 O(logN)을 보장.

**파이썬 이진 탐색 라이브러리**  
```py
bisect_left(a, x)
```
정렬된 순서를 유지하면서 배열 a에 x를 삽입할 가장 왼쪽 인덱스를 반환
```py
bisect_right(a, x)
```
정렬된 순서를 유지하면서 배열 a에 x를 삽입할 가장 오른쪽 인덱스를 반환
```py
from bisect import bisect_left, bisect_right

a = [1, 2, 4, 4, 8]
x = 4

print(bisect_left(a, x))   # 왼쪽에서부터 삽입될 위치인 2를 반환
print(bisect_right(a, x))  # 오른쪽에서부터 삽입될 위치인 4를 반환
```

**파라메트릭 서치(Parametric Search)**  
최적화 문제를 결정 문제('예' 혹은 '아니오')로 바꾸어 해결하는 기법.

예시)  
특정한 조건을 만족하는 가장 알맞은 값을 빠르게 찾는 최적화 문제
일반적으로 코딩 테스트에서 파라메트릭 서치 문제는 이진 탐색을 이용하여 해결할 수 있다.

출처 : https://velog.io/@1yangsh/algorithm-%EC%9D%B4%EC%A7%84-%ED%83%90%EC%83%89
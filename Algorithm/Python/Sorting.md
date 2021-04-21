# Sorting

<table>
<tr>
    <td>정렬 알고리즘</td>
    <td>평균 시간 복잡도</td>
    <td>공간 복잡도</td>
    <td align="center">특징</td>
</tr>
<tr>
    <td>선택 정렬</td>
    <td>O(N^2)</td>
    <td>O(N)</td>
    <td>아이디어가 매우 간단</td>
</tr>
<tr>
    <td>삽입 정렬</td>
    <td>O(N^2)</td>
    <td>O(N)</td>
    <td>데이터가 거의 정렬되어 있을 때는 가장 빠름</td>
</tr>
<tr>
    <td>퀵 정렬</td>
    <td>O(NlogN)</td>
    <td>O(N)</td>
    <td>대부분의 경우에 가장 적합하며, 충분히 빠름</td>
</tr>
<tr>
    <td>계수 정렬</td>
    <td>O(N+K)</td>
    <td>O(N+K)</td>
    <td>데이터의 크기가 한정되어 있는 경우에만 사용이 가능하지만 매우 빠르게 동작</td>
</tr>
</table>

# 선택 정렬

```py
## 선택정렬

array = [7, 5, 9 ,0 ,3 ,1, 6, 2, 4, 8]

def selectionSort(array):
    for i in range(len(array) - 1):
        min = i
        for j in range(i, len(array)):
            if array[min] > array[j]:
                min = j
        array[i], array[min] = array[min], array[i]
    return array

print(selectionSort(array))
```

# 삽입 정렬

```py
## 삽입정렬

array = [7, 5, 9 ,0 ,3 ,1, 6, 2, 4, 8]

for i in range(1, len(array)):
    for j in range(i, 0, -1):
        if array[j] < array[j - 1]:
            array[j], array[j - 1] = array[j - 1], array[j]
        else:
            break

print(array)
```

# 퀵 정렬

```py
# 퀵 정렬

data = [3, 7, 8, 1, 5, 9, 6, 10, 2, 4]


def quickSort(data):
    n = len(data)

    if n <= 1:
        return data
    else:
        pivot = data[0]
        less = [x for x in data[1:] if x <= pivot]  # pivot 보다 작은 값
        greater = [x for x in data[1:] if x > pivot]  # pivot 보다 큰 값
        return quickSort(less) + [pivot] + quickSort(greater)


print(quickSort(data))
```

출처 : https://velog.io/@1yangsh/algorithm-%EC%A0%95%EB%A0%AC-u9z8q3he
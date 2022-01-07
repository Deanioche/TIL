

## [퀵 정렬 - Quick Sort] 파이썬 구현

```py
def quick_sort(arr):
    
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    lesser_arr, equal_arr, greater_arr = [], [], []
    
    for num in arr:
        if num < pivot:
            lesser_arr.append(num) #작은 리스트로 보내기
        elif num > pivot:
            greater_arr.append(num) #큰 리스트로 보내기
        else:
            equal_arr.append(num)

	#작은 리스트와 큰 리스트끼리 다시 재귀하여 퀵정렬
    return quick_sort(lesser_arr) + equal_arr + quick_sort(greater_arr)
```

## [이분 탐색 - Binary Search] 파이썬 구현

```py
def BinarySearch(arr, val, low, high):
    if low > high:
        return False #해당 배열에 타겟 숫자 미존재
    
    mid = (low + high) // 2 #위치 기반으로 찾는 것
    
    if arr[mid] > val:
        return BinarySearch(arr, val, low, mid - 1) #수가 중앙 값보다 아래 있는 경우
    elif arr[mid] < val:
        return BinarySearch(arr, val, mid + 1, high) #수가 중앙 값보다 위에 있는 경우
    else:
        return True #아니면 숫자를 출력 -> return val
```
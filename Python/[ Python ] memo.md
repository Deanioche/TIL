# Python memo



8. 파이썬 reduce 함수 사용법

https://www.daleseo.com/python-functools-reduce/

(json 같이 key:value 데이터가 담긴) iterable 객체에서 모든 요소의 key가 갖고있는 value를 집계할수 있는 함수 (예 : 총합)
___

## **7. join 함수**

split()과 반대로 iterable 객체 요소 사이사이에 문자를 넣어 하나의 문자열로 합쳐주는 함수.

```py
a = ",".join('abcd')
print(a)  # a,b,c,d

a = "_".join(['a', 'b', 'c', 'd'])
print(a)  # a_b_c_d
```
____

## **6. filter 함수**

함수가 True로 return한 요소들 모아 리스트로 만든다. for loop를 닮았지만 내장 함수이고 속도가 빠르다.

```py
number_list = range(-5, 5)
less_than_zero = list(filter(lambda x: x < 0, number_list))
print(less_than_zero)

# Output: [-5, -4, -3, -2, -1]
```

___

## **5. lambda 형식**

https://velog.io/@matisse/%EC%9E%85%EB%A0%A5%EA%B0%92-%ED%95%A8%EC%88%98-%EB%A7%8C%EB%93%A4%EA%B8%B0

람다 형식은 함수를 딱 한 줄만으로 만들게 해준다.

- 사용법
    ```
    lambda arg1, arg2, ... : expr
    ```

- def와 lambda 비교
    ```py
    def hap(x, y):
        return x + y

    print(hap(10, 20)) # 30

    print((lambda x,y: x + y)(10, 20)) # 30
    ```

___

## **4. map 함수**

https://velog.io/@suasue/Python-map-%ED%95%A8%EC%88%98

- map의 첫 번째 파라미터는 **함수**, 두 번째로는 **iterable 객체**가 들어간다.  
- 실행시, iterable 객체의 요소 하나하나가 **함수**의 argument로 들어가 값이 수정되고 각각의 값을 generator형으로 반환한다. 
- list형으로 반환하기 위해서는 list()로 감싸주어야 한다.

```py
# list 생성
a = [1.2, 2.5, 3.7, 4.6]
a = list(map(int, a))

print(a)  # [1, 2, 3, 4]


# 모든 요소 + 100
def plus100(n):
    return n + 100

a = list(map(plus100, a))

print(a)  # [101, 102, 103, 104]


# 일회용 함수 사용 (람다식)
a = list(map(lambda n: n + 100, a))

print(a)  # [201, 202, 203, 204]
```

```py
# 입력받은 값을 정수로 변환
a, b = map(int, input().split())
```

```py
list(map(lambda x: x ** 2, range(5))) # [0, 1, 4, 9, 16]
```

___

## **3. sys.stdin.readline() 사용하기**

[**ref_link**](https://velog.io/@yeseolee/Python-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%9E%85%EB%A0%A5-%EC%A0%95%EB%A6%ACsys.stdin.readline)

한 두줄 입력받는 문제들과 다르게, 반복문으로 여러줄을 입력 받아야 할 때는 input()으로 입력 받는다면 시간초과가 발생할 수 있습니다. 대표적인 예시가 백준 BOJ 15552번 문제입니다.

### **# 주의할 점**

- 개행문자(\n)가 함께 입력되므로 제거 필요.
- 정수로 받을시, str -> int 형변환 필요.

### **# 정수 입력**

- 한 개의 정수를 입력받을 때
    ```py
    import sys
    a = int(sys.stdin.readline())
    ```

    - int()는 파라미터로 들어오는 문자열을 정수형(Integer)으로 바꿔준다.

- 여러 개의 정수를 한 줄에 입력받을 때
    ```py
    import sys
    a, b, c = map(int, sys.stdin.readline().split())
    ```
    
    - map()은 iterable 객체(list 등)의 각 요소들을 지정한 함수로 처리해주는 함수.

    - split()은 파라미터안에 넣은 문자를 기준으로 문자열을 나눠주는 함수. 아무것도 안넣으면 공백 문자(스페이스, 탭, 엔터 등)으로 나눈다.

- 임의의 개수의 정수를 한 줄에 입력받아 list에 저장
    ```py
    import sys
    data = list(map(int,sys.stdin.readline().split()))
    ```

    - list()는 자료형을 리스트형으로 변환해주는 함수.

- 임의의 개수의 정수를 n줄 입력받아 2차원 리스트에 저장할 때

    ```py
    import sys
    data = []
    n = int(sys.stdin.readline())
    for i in range(n):
        data.append(list(map(int,sys.stdin.readline().split())))
    ```

    - data의 각 요소의 길이가 달라도 된다.

- 문자열 n줄을 입력받아 리스트에 저장할 때

    ```py
    import sys
    n = int(sys.stdin.readline())
    data = [sys.stdin.readline().strip() for i in range(n)]
    ```

    - strip()은 문자열 맨 앞과 맨 끝의 공백문자를 제거

    - 입력
        ```
        3
        그래도
        감사해요
        나중에 봐요
        ```
    - 출력
        ```
        ['그래도', '감사해요', '나중에 봐요']
        ```

___

## **2. list, tuple, dict 초기화**

```py
list = []
tuple = ()
dict = {}

print(type(list), list)
print(type(tuple), tuple)
print(type(dict), dict)

# 실행 결과
# <class 'list'> []
# <class 'tuple'> ()
# <class 'dict'> {}
```
___


## **1. 에디터에서 코드 입력 후 Shift + Enter**

파이썬 인터프리터가 켜지며 커서가 가리키는 코드 한 줄이 실행됨.

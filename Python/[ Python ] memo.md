# Python memo

## range() 역순으로 받기

```py
for i in range(5, 0, -1):
    print(i) # 5 4 3 2 1

for i in reversed(range(0, 5)):
    print(i) # 4 3 2 1 0
```

___
## **배열 뒤집는 방법 2가지**

```py
a = [1, 2, 3]
a.reverse()
print(a) # [3, 2, 1]

a = [1, 2, 3]
print(list(reversed(a))) # [3, 2, 1]
```

___
## **for loop에서 index, value 둘다 받기**

- enumerate() 함수 사용
    ```py
    for i, v in enumerate(['tic', 'tac', 'toe']):
        print(i, v)
        
    # 0 tic
    # 1 tac
    # 2 toe
    ```

- dict 응용
    ```py
    dictionary = {'a': 0, 'z': 25}
    for index, (key, value) in enumerate(dictionary.items()):
        ## Code here ##
    ```
___

## **문자열 반복**

```py
print('A' * 5) # AAAAA
```
___

## **아스키코드 <-> 문자 ord(c) chr(n)**

- ord(문자) : 문자를 10진법 아스키 코드로 표기
- chr(숫자) : 10진법 아스키 코드를 문자로 표기

```py
print(ord('A')) # 65
print(ord('a')) # 97
print(chr(65))  # A
print(chr(97))  # a
print(chr(48))  # 0
```

___

## **import random**

```py
from random import *
 
i = randint(1, 100)  # 1부터 100 사이의 임의의 정수
print(i)
 
f = random()   # 0부터 1 사이의 임의의 float
print(f)
 
f = uniform(1.0, 36.5)   # 1부터 36.5 사이의 임의의 float
print(f)
 
i = randrange(1, 101, 2) # 1부터 100 사이의 임의의 짝수
print(i)
 
i = randrange(10)  # 0부터 9 사이의 임의의 정수
print(i)
```

**# 샘플링**

리스트에서 랜덤으로 샘플 뽑기.
```py
import random

# (1) 숫자리스트 샘플링
numlist = [1,2,3,4,5,6,7,8,9]
s = random.sample(numlist, 3)
print(s)  # [1, 2, 8]
 
# (2) 튜플 샘플링
frutes = ('사과', '귤', '포도', '배')
s = random.sample(frutes, 2)
print(s)  # ['배', '사과']
```
___

## **퍼센테이지 포멧 출력 방법**
```py
print(f"{-21.47483648:.0f}%")  # -21%
print(f"{-21.47483648:.3f}%")  # -21.475%
print(f"{-21.47483648:.5f}%")  # -21.47484%
``` 
___

## **statistics 라이브러리 사용시 시간 차이**
![image](https://user-images.githubusercontent.com/66513003/138732347-9f9e6201-d94c-4b7b-b6ff-6dbd83c31f86.png)

위 - 안사용(72ms)  
아래 - 사용(164ms)

## **15. set 집합**

- set 집합 안에서는 모든 원소가 고유한 값은 가진다. (중복 값이 없음)

- list -> set으로의 변환은 list 안의 중복된 원소를 모두 제거한다.
    ```py
    import sys
    input = sys.stdin.readline

    lst = []
    for i in range(0, 10):
        lst.append(int(input()) % 42)

    print(len(set(lst)))

    # list -> set은 배열에서 중복값을 제거
    ```

https://wikidocs.net/16044

## **14. join**

```py
lst = [0] * 5
print("\n".join(map(str, lst)))

# 출력 결과
# 0
# 0
# 0
# 0
# 0
```


## **13. 리스트 0으로 초기화**
```py
lst = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0] 
# 위와 같이 만들 때

lst = [0] * 10 # 빠름
lst = [0 for i in range(10)] # 느림
lst = list(0 for i in range(10)) # 느림
```

## **12 . zfill(n) 함수**
```py
N = "26"
print(N.zfill(5)) # 00026
```
문자열 N이 5자리보다 짧으면 앞을 zero(0)으로 채운다.  
N이 정수형이면 에러.

**### 예제** [BaekJoon_1110](https://www.acmicpc.net/problem/1110)
```py
N = "26"
print(f"{sum(map(int, N.zfill(2)))}"[-1])
# 1. 문자열 N이 2자리가 안되면 앞을 0으로 채우고(N.zfill(2))
# 2. 각 자리를 int로 바꿔 sum() 하고 이걸 문자열로 다시 받아(f"{...}") 뒤에서 첫 문자([-1])를 출력.
```


## **11. 문자열[-n]**
```py
N = "12345" 
print(N[-1]) # 5 - 뒤에서 첫번째 문자
print(N[-4]) # 4 - 뒤에서 네번째 문자
print(N[-3:]) # 345 - 뒤에서 세번째 문자부터 쭉
print(N[:-2]) # 123 - 뒤에서 두번째 문자까지 제외하고 전부 출력
```

## **10. // 연산자**
```py
print(26 // 10) # 2
print(71 // 10) # 7
```
소수점 이하를 버림. int형태로 출력.

## **9. {aa=} '변수명=값' 출력**

```py
aa = 0
bb = 1 if aa == 0 else aa
print(f'{aa=} {bb=}')  # aa=0 bb=1
```
f'{변수명=}'는 '변수명=값'의 형태로 출력된다. (aa=0)

___

## **8. 파이썬 reduce 함수 사용법**

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

# Python memo

# **(미해결)Integet sequence 규칙 찾기**

```py
for n in range(1, 26):
    print(int((4*n-3)**0.5), end="")
# 1233445556667777888899999
```

- 원하는 규칙에 따른 수열을 생성하는 방법을 위와 같이 한 줄로 표현하는 방법을 찾아야한다.
    ```py
    # Integer Sequence 1 ~ 10, n은 n개만큼 출력 (ex. 9는 9개 출력)
    j = 1
    for i in range(1, 11):
        n = i
        print(j, end="")
        while n:
            n -= 1
            j += 1
        print(f" ~ {j - 1} => {i}", end="\n")

    # 출력 결과
    # 1 ~ 1 => 1
    # 2 ~ 3 => 2
    # 4 ~ 6 => 3
    # 7 ~ 10 => 4
    # 11 ~ 15 => 5
    # 16 ~ 21 => 6
    # 22 ~ 28 => 7
    # 29 ~ 36 => 8
    # 37 ~ 45 => 9
    # 46 ~ 55 => 10
    ```
___

## 함수 앞 *의 의미
반환되는 값을 가변적인 갯수를 가진 위치 인수로 정의.
`<map object at ~~~>` 처럼 여러 값을 가져 한번에 출력할 수 없는 객체를 출력시킬 때 쓰는듯??
```py
print([map(int, "1 2 3 ".split())])  # [<map object at 0x0000025FA3CA1130>]
print([*map(int, "1 2 3 ".split())])  # [1, 2, 3]

print(*map(int, "1 2 3 ".split()))  # 1 2 3
```
___

## while문 조건 입력 중, 변수에 값 지정

```py
while s := input(): # 아무것도 입력하지 않으면 while문 종료
    print('yneos'[s != s[::-1]::2])
    print(s[::-1])  # 뒤집기
    print(s[::2])  # 인덱스 0, 2, 4, ...
    print(s[::3])  # 인덱스 0, 3, 6, ...
```
___

## exec() 함수
파라미터로 들어오는 문자열을 코드로써 실행한다.

특정 코드를 반복할 때 for문 대신 사용할 수 있다.

```py
exec('print("문자열을 여러번 반복");'*3)
# print("문자열을 여러번 반복");print("문자열을 여러번 반복");print("문자열을 여러번 반복");

a = 2
n = int(input()) - 1
exec('a *= 2;'*n)
print(a)  # 10 입력시 -> 1024 
# 2 ** n 와 같음
```
___

## n의 보수 (숏코딩)

음수로 바꾸고(-) 비트반전(~) 시켜주면 원래 값에 -1한 값이 된다.

```py
n = 10
~-n == n-=1  # 9

print(~-n)  # 9
print(~n)  # -11
```

___

## 두 리스트(배열)의 각 자리 원소 값 합치기
https://itinerant.tistory.com/2
```py
a = [1,2,3,4,5]
b = [5,4,3,2,1]
c = [x+y for x,y in zip(a, b)]

# [6, 6, 6, 6, 6]
```

```py
c = [a[i] + b[i] for i in range(len(a))]

# [6, 6, 6, 6, 6]
```


- 아래 두 식(1, 2)은 동일한 연산을 수행.
    ```py
    # 1
    a = [1, 2, 3, 4, 5]
    b = [5, 4, 3, 2, 1]

    c = [aa+bb for aa in a for bb in b]
    # [6, 5, 4, 3, 2, 7, 6, 5, 4, 3, 8, 7, 6, 5, 4, 9, 8, 7, 6, 5, 10, 9, 8, 7, 6]

    print(c)

    # 2
    for aa in a:
        for bb in b:
            print(aa+bb, end=", ")
    # 6, 5, 4, 3, 2, 7, 6, 5, 4, 3, 8, 7, 6, 5, 4, 9, 8, 7, 6, 5, 10, 9, 8, 7, 6,
    ```
___

## 코드 실행시간 체크

```py
start = time.time()  # 시작 시간 저장

# 실행할 코드

print("WorkingTime: {:.3f} sec".format(time.time() - start))
```
___

## **에라토스테네스의 채**
2~10까지 소수 구하는 코드
```py
n = 10
a = [False, False] + [True]*(n-1)
primes = []

for i in range(2, n+1):
    if a[i]:
        primes.append(i)
        for j in range(2*i, n+1, i):
            a[j] = False
print(primes)
```

![image](https://blog.kakaocdn.net/dn/k46OV/btq2Nx3GU7j/hQiuyWWdNmIK9J0W96CEZ1/img.gif)

[tistory](https://this-programmer.tistory.com/409)

[wikidocs](https://wikidocs.net/21638)

___

## **zip() 함수**

[ref](https: // itinerant.tistory.com/2)

```py
l = [1, 2, 3, 4, 5, 6]
o = [-1, -2, -3, -4, -5, -6]
print(list(zip(o, l)))
# [(-1, 1), (-2, 2), (-3, 3), (-4, 4), (-5, 5), (-6, 6)]

for i in [a - b for a, b in zip(o, l)]:
    print(i, end=" ")
    # -2 -4 -6 -8 -10 -12
```

___

## **제곱 square**

```py
print(f"{n ** 0.5 = }")  # n ** 0.5 = 2.0
print(f"{n ** -1 = }")  # n ** -1 = 0.25
print(f"{n ** -2 = }")  # n ** -2 = 0.0625
print(f"{n ** 0.3 = }")  # n ** 0.3 = 1.515716566510398
print(f"{n ** 0.6 = }")  # n ** 0.6 = 2.2973967099940698
```
___

## **python 진수 변환**

https://www.daleseo.com/python-int-bases/

- n -> 10진수
    ```py
    n = input()
    print(int(n, 16)) # 16진수 A -> 10
    ```

```py
# 10 -> n 진수
def solution(n, q):
    rev_base = ''

    while n > 0:
        n, mod = divmod(n, q)
        rev_base += str(mod)

    return rev_base[::-1]
    # 역순인 진수를 뒤집어 줘야 원래 변환 하고자하는 base가 출력


print(solution(45, 3)) # 1200

# n -> n 진수
print(solution(int('c', 16), 4)) # 30
```

## **하위 문자열 비교**

- in
    가장 빠름
    ```py
    >>> 'foo' in '**foo**'
    True

    >>> 'foo' not in '**foo**'
    False
    ```

- any()
    가장 파이썬스러운 문법
    ```py
    names = ['bob', 'john', 'mike']
    print(any(st in 'Hey bob!' for st in names))
    ```

- find
    가장 먼저 발견된 문자열의 인덱스 리턴
    ```py
    s = "This be a string"
    print(s.find("is"))  # 2
    print(s.find("This"))  # 0
    print(s.find("ing"))  # 13
    ```
    ```py
    s = "This be a string"
    for i in s:
        print(i.find("s"))
    # 출력 결과
    # -1
    # -1
    # -1
    # 0
    # -1
    # -1
    # -1
    # -1
    # -1
    # -1
    # 0
    # -1
    # -1
    # -1
    # -1
    # -1
    ```

- __contains__도 존재하지만 권장되지 않음.  
    __함수명__은 사용자함수.

## 리스트를 문자열로
```py
print(''.join(['1', '2', '3']))  # 123
```

___

## range() 역순으로 받기

```py
for i in range(5, 0, -1):
    print(i) # 5 4 3 2 1

for i in reversed(range(0, 5)):
    print(i) # 4 3 2 1 0
```

___
## **배열 뒤집는 방법 3가지**

```py
print("ABCDEF"[::-1])  # FEDCBA
print([1, 2, 3][::-1])  # [3, 2, 1]

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

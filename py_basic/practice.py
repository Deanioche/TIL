print(3*(3+1))


print(not True)
print(not (5 > 10))
print(not 5 > 10)
print(not 5, "23")

age = 4

print("나이는", str(age), "살")

name = "홍길동"

print(name + "님") # 홍길동님
print(name, "님") # 홍길동 님

''' 연산자 '''

print(10/3) # 3.3333...
print(2**3) # 2^3 = 8
print(10%3) # 1
print(3 % 10) # 3으로 10을 나눌 수 없으므로 몫은 0이고 3이 그대로 나머지로 남는다.
print(5//3) # 1 몫
print(10//3) # 3 몫

print( 5 >= 10) # False
print( 5 <= 10) # True
print(3 == 3) # True
print(3 != 3) # False

print(not (1 != 3)) # False
print((3 > 0) and (3 < 5)) # True
print ((3 > 0) & (3 < 5)) # True

print((3 > 0) or (3 < 5)) # True
print ((3 > 0) | (3 < 5)) # True

print(5 > 4 > 3) # True
# 위 아래는 같은 수식
print((5 > 4) and (4 > 3)) # True

print(5 > 4 > 7) # False

''' 수식 '''

num = 18

num %= 5 # num을 5로 나눈 나머지
print(num)  # 3


# 36:28 continue

print(abs(-5)) # 5
print(pow(4,3)) # 64
print(max(2, 12 , 5)) # 12
print(min(2, 12 , 5)) # 2
print(round(3.14)) # 3
print(round(4.99)) # 반올림 5

from math import *

print(floor(4.99)) # 내림 4
print(ceil(4.99)) # 올림 5
print(sqrt(4.99)) # 제곱근 2.233830790368868
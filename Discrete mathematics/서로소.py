from math import gcd

# 서로소는 어떤 자연수와의 최대공약수가 1인 수

# gcd는 입력된 두 수의 최대공약수를 반환

print(gcd(7, 6)) # 최대공약수 1

# 100미만의 수 중에 2436의 서로소
for i in range(1000):
    if gcd(13, i) == 1:
        print(f"서로소2 : {i}")

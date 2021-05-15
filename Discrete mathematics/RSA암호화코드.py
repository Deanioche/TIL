# 암호화 할 문자열을 숫자코드화한 값 -> o

import math

o = 123456 # LEE777

print("암호화 할 문자열 :", o)
print()

p = 47
q = 89
n = 4183
e = 97

k = (p-1)*(q-1)

d = 0

for i in range(k):
    if (i * e % k) == 1:
        d = i

seperate = 2
if 25 < n < 2525:
    seperate = 2
elif 2525 < n < 252525:
    seperate = 4
elif 252525 < n < 25252525:
    seperate = 6

sp = math.ceil(len(str(o)) / seperate) # 나눌 자리수에 맞춰 loop회수 저장

oo = {}
rr = {}
암호화된코드 =""

for j in range(1, sp + 1):
    oo[j] = int(str(o)[seperate * (j - 1):seperate * j]) # 자리수 나누어 저장
    rr[j] = pow(oo[j], e) % n # 암호화
    암호화된코드 += str(rr[j])

print("암호화 전 : ", oo)
print("암호화 후 : ", rr)
print("암호화 후 : ", 암호화된코드)
print()

pp = {} # 복호화 결과
result = ""

for l in range(1, len(rr) + 1):
    pp[l] = pow(rr[l], d) % n # 복호화
    result += str(pp[l])

print("복호화 후 :", pp)
print("복호화 후 :", result)
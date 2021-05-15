# RSA암호화에서 개인키 d를 구하는 코드
# k = (p-1)(q-1)값 입력
# e = 공개키 (n, e)의 e값 입력

k = 4048
e = 97

for i in range(k):
    if (i * e % k) == 1:
        print("d :", i)


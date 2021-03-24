''' 랜덤 함수 '''

from random import *

print(random()) # 0.0 ~ 1.0 미만의 임의의 값 생성
print(random())
print(random())

print(random() * 10) # 0.0 ~ 10.0 

print(int(random() * 10)) # 소수점 제거
print(int(random() * 10) + 1) # 1부터 10이하

print(int(random() * 45) + 1) # 1 ~ 45

print(randrange(1, 46)) # 1 ~ 46 미만의 랜덤값 생성
print(randint(1, 45)) # 1 ~ 45 이하 값 생성

print(randint(4, 28)) # 예제



''' 문자열 '''


sen1 = "큰따옴표"
sen2 = '작따옴표'
sen3 = """
큰따옴표
    세개를
        쳤습니다
    아주
        세게
"""
print(sen1)
print(sen2)
print(sen3)



''' 슬라이싱 '''


jumin = "990914-1010235"

print("age : " + jumin[7])
print("year : " + jumin[0:2]) # 0부터 2직전까지 (0 ~ 1)
print("month : " + jumin[2:4])
print("month : " + jumin[4:6])
print("birth : " + jumin[:6]) # 처음부터 6 직전까지
print("뒤 7 자리 : " + jumin[7:]) # 7번째부터 끝까지
print("뒤 7자리 ( 뒤에부터 ) : " + jumin[-7:]) # 맨 뒤에서 7번째부터 끝까지


''' 문자열 처리 '''


python = "Python is Amazing"
print(python.lower())
print(python.upper())
print(python[0].isupper()) # True
print(len(python)) # len 길이 17
print(python.replace("Python", "Flutter")) # replace

index = python.index("n")
print(index) # n은 5번 인덱스

index = python.index("n", index + 1) # 두번째 n을 찾음 15
print(index)

print(python.find("응애")) # index()와 기능이 같지만 문자를 못찾으면 -1 반환 

# index = python.index("응애") # index()는 문자를 못찾으면 에러

print(python.count("n")) # 문자열 python에 n이 몇개있나


# 01:01:32 continue...


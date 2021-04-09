
# 사이트 별로 비밀번호를 만들 ㅓ주는 프로그램을 작성하시오.
# 예) http://naver.com
# 규칙 1 : http:// 부분은 제외 => naver.com
# 규칙 2 : 처음 만나는 점(.) 이후 부분은 제외 => naver
# 규칙 3 : 남을 글자 중 처음 세자리 + 글자 갯수 + 글자 내 'e' 갯수 + "!"로 구성
#                   (nav)               (5)     (1)              (!)
# 예) 생성된 비밀번호 : nav51!


url = "https://naver.com"
url = "https://google.com"
url = "https://egloo.com"
url = "https://efunket.com"
r1 = url[url.index("/") + 2:]
r2 = r1[:r1.index(".")]
r3 = r2[:3] + str(len(r2))+ str(r2.count("e")) + "!"
print(f"{url} 의 비밀번호는 {r3} 입니다")
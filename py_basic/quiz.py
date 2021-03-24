print(r"https://nadocoding.tistory.com/34?category=902275")

'''
Quiz) 사이트 별로 비밀번호를 만들어주는 프로그램을 작성하시오.

예) http://naver.com
규칙1 : http:// 부분은 제외 → naver.com
규칙2 : 처음 만나는 점(.) 이후 부분은 제외 → naver
규칙3 : 남은 글자 중 처음 세 자리 + 글자 갯수 + 글자 내 'e'의 갯수 + '!'로 구성
                       (nav)                      (5)                   (1)             (!)

예) 생성된 비밀번호 : nav51!


http://naver.com 일 때
 → nav51!

http://daum.net 일 때
 → dau40!

http://google.com 일 때
 → goo61!

http://youtube.com 일 때
 → you71!

'''

url = "http://naver.com"
# url = "https://google.com"

url2 = url[url.index("//") + 2:]

print("url2 : " + url2)

url3 = url2[:url2.index(".")]

print(url3)

key = str(url3[:3]) + str(len(url3)) + str(url3.count("e")) + "!"

print(key)


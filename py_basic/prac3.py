print("a" + "b")
print("a", "b")

# 방법 1
print("나는 %d 살 입니다." % 20)
print("나는 %s을 좋아해요." % "파이썬")
print("나는 %s요." % "추워")

print("나는 %s색과 %s색을 좋아해요." %("추워", "응애"))

# 방법 2
print("나는 {}살 입니다." .format(20))
print("나는 {}색과 {}색을 좋아해요." .format("응아", "웅앙"))
print("나는 {1}색과 {0}색을 좋아해요." .format("첫번째", "두번째"))

# 방법 3
print("나는 {age} 살이며, {color}색을 좋아해요" .format(age=20, color="빨간"))

# 방법 4
age = 20
color = "파랑"
print(f"응애는 {age}살이고, {color}이 싫어요" .format(age = "응애", color = "핳앟")) # 20, 파랑이 뜸
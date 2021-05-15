num = int(input("수?"))

for i in range(1, num+1):
    if num % i == 0:
        # 약수임
        print(i, end=' ')
        
print()

isPrime = True

for j in range(2, num):
        if num % j == 0:
            isPrime = False

print("isPrime :", isPrime)
## **반복문**

___

for 명령, while 명령

## **for 명령**

```
for variable [in word...]; do
    command...
done
```

- word … 부분(값의 목록)을 먼저 확장함
- word 목록에 존재하는 값을 순차적으로 변수 variable 에 대입하고 do 와 done 사이의 명령을 수행함
- word 부분이 없다면 in '$@'가 있는 것으로 가정함
    word … 부분(값의 목록)을 먼저 확장함
- word 목록에 존재하는 값을 순차적으로 변수 variable 에 대입하고 do
와 done 사이의 명령을 수행함
- word 부분이 없다면 in '$@'가 있는 것으로 가정함
- '$@' 은 모든 인수를 하나하나 따로 삽입되는 걸로 처리.

### **# 예제**
```py
$ for i in Kim Lee Park; do echo $i; done
Kim
Lee
Park

$ echo {A..D}
A B C D

$ for i in {A..D}; do echo $i; done
A
B
C
D
```

```py
$ cat testFor.sh
#!/bin/bash
for FILE
do
echo $FILE
done
$ chmod u+x testFor.sh
$ ./testFor.sh `ls`
```
ls 출력 결과가 한줄한줄 나온다.

___

## **for 명령2**

C나 JAVA에서 사용하는 형태

```
for (( exp1; exp2; exp3 )); do
    command...
done
```

- exp1~exp3 은 수식으로 각각 생략이 가능함
- exp1는 제어 변수의 초기화를 위해 한 번 수행됨
- exp2 가 참인 동안 명령과 exp3 이 반복 수행됨

### **실행**
```py
$ cat testFor3.sh
#!/bin/bash
LIMIT=10
for ((a=0; a<LIMIT; a++)); do
    echo "$a"
done

$ . testFor3.sh # 실행
0
1
2
... 
8
9
```

___

## **while 명령**

```
while command...; do
    command...
done
```

- while 다음에 나오는 명령을 실행하여 참 또는 거짓을 판단함
- if 명령과 마찬가지로 종료 상탯값이 0이면 참으로 판단
- 조건 비교를 위해 test expression또는 [ expression ]을 자주 사용함

```py
$ cat testWhile.sh
#!/bin/bash
N=1
S=0
while [ $N -le 10 ]; do
    echo -n "$N "
    S=$[$S+$N]
    N=$[$N+1]
done
echo
echo $S 

# 실행
$ . testWhile.sh 
1 2 3 4 5 6 7 8 9 10
55
```
- -le : <= less equal

___

## **복합명령 '((  ))'**

(( expression ))은 수식 계산에 사용되는 복합 명령
- let "expression"과 동일하며 test 명령어 대신 사용 가능
- while 다음의 (( expression ))에서 수식 결과가 0이 아닌 경우 종료 상탯값이
0이 되며 참으로 판단

```py
echo $(( 8 + 8 )) # 16
```

```py
$ cat testWhile2.sh
#!/bin/bash
LIMIT=10
((a=0))
while (( a<LIMIT )); do
echo "$a"
(( a++ ))
done

# 실행
$ ./testWhile2.sh
0
1
...
8
9
```

___

## **until 명령**

조건이 만족될 때까지(거짓인 동안) 명령을 반복하여 수행.

```
until command...; do
    command...
done
```

- until 다음에 나오는 명령이 참이 될 때까지 반복함
    - 즉, 거짓인 동안 반복하게 됨
- 조건을 표시하기 위해 test expression, [ expression ] 또는 (( expression ))을 사용할 수 있음

```py
$ cat testUntil.sh
#!/bin/bash
N=1
S=0
until [ $N -gt 10 ]; do
    echo -n "$N "
    let S=$S+$N
    let N=$N+1
done
echo
echo $S

# 실행
$ . testUntil.sh
1 2 3 4 5 6 7 8 9 10
55
```
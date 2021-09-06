## **조건문**

___

if 명령, case 명령

## **if문**
```
if command...; then
command...
[ elif command...; then
command... ]...
[ else
command...]
fi
```

- then을 다음 줄로 넘기는 경우 세미콜론을 쓰지 않아도 된다.

- if 다음의 명령을 실행하여 참이면 then 다음의 명령을 실행함(if 명령은 종료됨)
    - if나 elif 다음에 조건 검사를 위한 test 명령을 사용할 수 있음
    - if나 elif 다음에 나오는 마지막 명령의 종료 상탯값으로 참과 거짓을 구분함
    - 종료 상탯값 0은 성공적 종료를 의미하며 참으로 간주함
- 거짓이면 elif 다음의 명령을 실행하여 참/거짓을 판단하고 실행함
- 만족되는 것이 없으면 else 다음의 명령을 실행함

```py
$ cd /usr/bin
$ echo $?
0 # 성공

$ cd /bin/usr
bash: cd: /bin/usr: 그런 파일이나 디렉터리가 없습니다
$ echo $?
1 # 실패

$ if true; then
> echo "Success"
> else
> echo "Failure"
> fi
Success

$ if true; false; then
> echo "True"
> fi
```

- '$?'는 직전에 사용한 함수의 종료 상태를 반환
    - 정상 종료 : 0
    - 실패 : 1

- true는 종료 상태값을 항상 0으로 지정

___

## **test 명령**

조건 검사를 위해 사용하는 명령
- 조건이 만족되면 종료 상탯값으로 0(참)을, 아니면 1(거짓)을 리턴함

```
test expression 또는 [ expression ]
```
- expression은 파일의 상태 검사, 문자열의 비교, 정수 비교를 위한 수식
- 대괄호와 expression 사이에 **공백이 있어야 함**

```py
$ if test -f .bashrc; then # 정규파일 .bashrc가 존재하면,
> echo "It's a regular file."
> fi
It's a regular file.

$ if [ -f .bashrc ]; then # 정규파일 .bashrc가 존재하면,
> echo "It's a regular file."
> fi
It's a regular file.
```

**수식에 사용되는 연산자**

![image](https://user-images.githubusercontent.com/66513003/132215647-51c48ba9-cb43-4136-9e75-c1d1cdf1f40c.png)

- 예
    ```py
    $ cat intCompare.sh
    #!/bin/bash
    if [ $# != 2 ]; then
    echo "You must supply two numbers as arguments"
    exit 1
    fi
    if [ $1 -eq $2 ]; then
    echo "$1 equals to $2."
    elif [ $1 -gt $2 ]; then
    echo "$1 is greater than $2."
    else
    echo "$1 is less than $2."
    fi
    echo "$1 + $2는 $[$1+$2]입니다."

    $ chmod u+x intCompare.sh

    $ ./intCompare.sh 36 68
    36 is less than 68.
    36 + 68는 104입니다.
    ```

- 간단한 T/F 판별 명령어
    ```py
    if [ "123" == 123 ]; then echo "T"; else echo "F"; fi    # T
    ```

- 다중 조건 
    조건 하나당 대괄호 하나씩 씌워주어야 한다.
    ```py
    if [ "123" == 123 ] && [ 2 == 2 ]; then echo "true"; else echo "F"; fi  # T

    if [ "123" == 1243 ] || [ 2 == 2 ]; then echo "true"; else echo "F"; fi    # T
    ```

___

## **case 명령**

다중 선택을 지원하는 복합 명령
- Java 언어에서 switch 문의 의미와 거의 같음

```
case word in
    [ pattern [ | pattern ]...) command...;; ]...
esac
```

- word 부분을 먼저 확장하고 pattern과 매칭되는지 검사함
- 매칭이 이루어지면 상응하는 명령이 수행됨
- 일단 매칭이 이루어지면 이후의 매칭 시도는 없음
- pattern 에서 *는 프로그래밍에서 ‘default 키워드’를 사용하는 것과 같음

**case 명령 패턴 사용 예**
![image](https://user-images.githubusercontent.com/66513003/132216916-2b72e310-eb19-4f8f-8293-b0622ea04328.png)

**명령어 예제**

- 스크립트
    ```py
    #!/bin/bash
    clear
    echo "
    Please Select:
    a. Display System Information
    b. Show Information about File Systems
    c. Summarize Disk Usage Information
    q. Quit
    "
    read -p "Enter selection [a, b, c, or q] > "

    case $REPLY in
        a|A) echo "Hostname: $HOSTNAME"
            uptime
            ;;
        b|B) df -h
            ;;
        c|C) if [ $(id -u) -eq 0 ]; then
            echo "All users' home disk Space utilization"
            du -sh /home/*
            else
            echo "($USER)' home disk Space utilization"
            du -sh $HOME
            fi
            ;;
        q|Q) echo "Program terminated."
            exit
            ;;
        *) echo "Invalid entry" >&2
            exit 1
            ;;
    esac
    ```

read -p 명령어로 값을 입력 받을 변수를 설정하지 않았으므로 $REPLY 변수로 들어간다.

___
## **Shell Script**

___

셸 명령어의 집합으로 이루어진 실행 가능한 텍스트 파일
- 셸이 파일의 내용을 읽어 처리함
- 선택/반복 등의 프로그래밍 구조를 사용할 수 있음
- 긴 작업, 반복적으로 일어나는 작업을 셸 스크립트로 작성할 수 있음
- 셸 스크립트를 새로운 명령어처럼 사용할 수 있음

- ~/.bash_profile, ~/.bashrc 등의 셸 초기화 스크립트
    - <표 3-10> 참고
- 디렉터리 /etc/rc.d/init.d/에 존재하는 시스템 초기화 스크립트

___

```
cat > [파일명]
```
텍스트 여러줄 입력 후 Ctrl + D로 [파일명]에 저장.

___

## **Shell Script의 실행 방법**

1. "bash [script_file]"
    - 스크립트 파일에 실행 권한을 추가할 필요가 **없음**
    - 명령 행에서 script_file 다음에 인수를 추가할 수 있음(모두 마찬가지)
    - **서브 셸을 새로 생성하여 스크립트를 실행**

2. "./[script_file]"
    - 스크립트 파일에 **실행 권한**을 추가해야 함
    - PATH 환경 변수에 설정된 디렉터리에서 스크립트 파일을 찾음
    - 스크립트 파일의 첫 행에서 `#!` 다음에 해석기(/bin/bash)를 지정함
    - **서브 셸을 새로 생성하여 스크립트를 실행**

3. "source [script_file]" 또는 ". [script_file]"
    - source는 셸의 내장 명령이며 **현재 셸**에서 스크립트 파일을 실행 함

___

## **Shell Script 문법**

#으로 시작하는 단어와 (같은 행에서) 이후에 나오는 내용은
주석으로 처리됨

**$0**은 스크립트 파일의 이름으로 확장됨

- source 명령으로 실행하는 경우는 셸의 이름(bash)으로 확장됨

**$1**은 첫 번째 인수, **$2**는 두 번째 인수로 확장됨

스크립트가 복잡하다면 적절한 echo 명령을 넣는 것이 좋음

변수=값 을 사용하여 변수에 값을 지정하고 $변수 를 사용하여 값을 추출할 수 있음
- 등호(=)의 좌우에 **공백**이 있으면 안됨

#### # 참고
- bash –x script_file과 같이 실행하면 수행되는 명령을 확인할 수 있음

___

## **변수의 사용**

선언 없이 변수를 사용할 수 있음
- MYCOLOR=blue 또는 echo $PATH

변수의 값은 기본적으로 문자열로 취급됨
- 연산이 필요하고, 변환이 가능한 경우에 정수로 다루어짐

변수의 이름 작명
- 대소문자의 구별
- 영문자, 숫자, 언더스코어(_) 문자로 구성
- 첫 자는 숫자가 될 수 없음

## **변수의 사용 예**

![image](https://user-images.githubusercontent.com/66513003/132207100-2b3decbe-acab-41f7-a355-d9537386029d.png)

```
a=ls
$a      # ls 명령어 실행
```

## **명령 행 인수**

Command Line Argument

셸이 스크립트를 처리할 때 사용되는 인수
- 사용자가 스크립트 실행에 필요한 입력값을 주어야 함

$0은 스크립트 파일의 이름으로 확장됨

나머지를 위치 매개변수(positional parameter)라 하며 $1, $2, $3 등은 이러한 인수를 의미함

```
$ cat > arg.sh
echo "This script's name is : $0"
echo Argument 1: $1
echo Argument 2: $2
$ chmod u+x arg.sh
$ ./arg.sh first second
This script's name is : ./arg.sh
Argument 1: first
Argument 2: second
$ /home/kdhong/arg.sh One Two
This script's name is : /home/kdhong/arg.sh
Argument 1: One
Argument 2: Two
```

## **특별한 매개 변수**

명령 행 인수와 관계가 있는 특별한 변수

변수의 값을 참조만 할 수 있음

![image](https://user-images.githubusercontent.com/66513003/132208491-c62ea898-9065-48ef-9a68-d7427ea8cd5f.png)


## **read 명령**

키보드로부터 한 라인을 읽은 후, 단어를 상응하는 변수에 저장함
- 대화식으로 스크립트를 실행시킬 수 있음

```
read [options] [variable…]
```

- 첫 번째 변수에 첫 번째 단어를, 두 번째 변수에 두 번째 단어를 저장
- 마지막 변수에 나머지 모두를 저장
- 남아 있는 변수가 있으면 빈 문자열이 됨
- 변수의 이름을 사용하지 않으면 셸 변수 REPLY에 저장됨
- 옵션 -p prompt 는 입력을 위한 프롬프트를 지정함
    - 입력 받기위한 변수를 따로 설정하지 않을 시 입력한 값은 **$REPLY**로 들어간다.

- ## **프롬프트를 이용한 변수 값 입력받는 법**
    ```
    $ read -p "Type your first name, last name, and address:" first last address
    Type your first name, last name, and address:Kildong Hong Songpa-gu, Seoul
    ```
    "Type your first name, last name, and address:" 라는 문자열에

    'first' 'last' 'address' 세 개의 변수를 생성,

    Kildong Hong Songpa-gu, Seoul를 입력하면 각각 띄어쓰기로 구문이 되어
    ```
    first : Kildong
    last  : Hong
    address : Songpa-gu, Seoul
    ```
    위와 같이 입력이 된다.

    그리고 변수를 호출하면,
    ```
    echo $first $last $address
    ```
    입력한 값이 출력된다.

___

## **함수의 사용**

셸 스크립트 파일에 함수를 정의할 수 있음

### **함수 사용 방법**
- 함수가 정의된 스크립트 파일에서 함수를 호출하여 사용할 수 있음
- 함수가 정의된 스크립트 파일을 실행하면 셸 환경에 함수 정의가 추가됨 그러면 같은 셸에서 함수 이름을 셸 명령어처럼 사용

### **함수 정의 방법**
```
function name { 
command... 
return 
}
 
# 또는

name ( ) {
command...
return
}
```

return [n] 문은 함수를 종료하는 문장으로 종료 상탯값을 리턴할 수 있음
- n이 생략되면 직전 명령의 종료 상탯값(exit status code)을 리턴

함수 정의를 항상 사용하려면 .bashrc에 넣는 것이 좋음
- alias 설정도 마찬가지임
- 셸이 시작될 때 항상 . ~/.bashrc가 실행되기 때문임

- 스크립트 파일 생성
    ```
    $ cat whoson.sh
    #!/bin/bash
    whoson () {
    date
    user=$USER
    echo "$user currently logged on"
    }
    echo "Step 1"
    whoson
    echo "Step 3"
    ```

- 실행
    ```
    $ . whoson.sh # . 으로 스크립트 실행
    Step 1
    2017. 03. 08. (수) 00:03:11 KST
    kdhong currently logged on
    Step 3

    $ whoson # 함수명으로 호출이 가능해 진다!
    2017. 03. 08. (수) 00:03:51 KST
    kdhong currently logged on

    $ echo $user
    kdhong
    ```

source [스크립트] 또는 . [스크립트]의 실행 방식은  
해당 스크립트를 다른 쉘이 아닌 현재 사용중인 쉘에서 실행하기 때문에  
생성한 함수가 쉘에 남아있게 되어 함수명 만으로 호출 할 수 있게 된다.  
.bashrc에 함수를 입력해 두면, 리눅스 부팅시 함수를 한번 실행하기 때문에 언제든 사용할 수 있게 된다

![image](https://user-images.githubusercontent.com/66513003/132211637-292c682a-5c45-42a7-92ad-d9774e0077ec.png)

```
su -sh ~    # home 디렉토리의 디스크 공간 사용량 출력 명령어
```
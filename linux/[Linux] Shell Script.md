# Shell Script

## **IO Redirection**

**`>`** : 출력되는 방향을 다른 곳으로 돌림 

### **Standard Output Redirection** 

- 커맨드 실행 후 출력되는 결과(Output)를 파일로 저장
    ```js
    ls -l > result.txt
    // 파일목록을 result.txt에 저장
    ```

- **Angle bracket**('>')은 **Standard Output**만 **Redirect**하므로 아래와 같이 출력되는 Error는 파일로 만들 수 없다
    ```js
    // result.html는 존재하지 않는 파일
    rm result.html > result.txt
    // 에러가 출력되지만 result.txt에 저장되지는 않는다.
    ```

- `>`에는 앞에 `1`이 생략되어 있는데, 이건 `Standard Output`을 의미한다. 
- **Angle bracket** 앞에 `2`를 붙여주면 에러를 **Redirection** 할 수 있다!

    ```js
    // result.html는 존재하지 않는 파일
    rm result.html 2> result.txt
    // 에러가 result.txt에 저장됨.
    ```

- 에러가 발생하지 않으면 result.txt에, 발생하면 error.log에 저장

    ```
    rm re.txt > result.txt 2> error.log
    ```

- 에러를 Standard Output으로 변환해 함께 저장되게 하기
    ```
    rm re.txt > result.txt 2>&1
    ```
    2>&1는 에러로 출력되는 메세지를 Standard Output으로 표준 출력화해, result.txt에 함께 저장이 된다.

### **Standard Input Redirection** 

- 파일에 저장된 값으로 입력받음

    ```js
    cat < hello.txt
    // hello.txt에 저장된 값이 출력된다.
    ```

    - Angle Bracket 유무의 차이
        - **cat hello.txt**는 cat이라는 프로그램의 **Command-line Arguments**(인자)로 들어가는 것
        - **cat < hello.txt**는 **Standard Input**으로 입력을 받는 것.

- Command-line Arguments와 IO Redirection 동시 사용
    ```js
    head -n1 < linux.txt > one.txt
    // '-n1' 는 head 프로그램의 Command-line Arguments로 들어감.
    // linux.txt는 Standard Input으로 입력됨 ('<')
    // one.txt에는 Standard Output으로 출력된 결과가 저장된다. ('>')
    ```

___

## Output 출력 결과가 파일에 append 되게 하기
```js
ls -al >> result.txt
// 반복 할수록 result.txt에 계속 추가된다.
```

___

## 여러 문자열을 한꺼번에 Input하기

```js
// mail 보내는 프로그램
mail asd@gmail.com <<qwerty
> 123
> qwe
> asd
> qwerty
// 보낼 문자열의 시작과 끝에 같은 단어를 입력하는걸로 입력을 마친다.
```

___

## dev/null (휴지통) 사용

커맨드 실행 결과를 화면에도 파일에도 출력하고싶지 않을 때
```
ls -al > /dev/null
```

____

## **Kernel vs Shell**

`커널`은 하드웨어를 직접적으로 제어하는 코어

`쉘`은 사용자가 리눅스에 입력한 명령을 커널이 이해할 수 있도록 번역해서 전달

<img src="https://user-images.githubusercontent.com/66513003/129032589-51d0cf33-406c-4145-9a0e-ac272e17a095.png" width="400">

___

## 여러 Shell을 써보기

### **bash vs zsh**

- 아래 명령어를 입력하면 현재 사용중인 shell이 출력된다.
    ```
    echo $0
    ``` 

- bash와 zsh의 차이
    - cd 입력 후 Tab키
        - zsh : 한번 누르면 파일목록 출력
        - bash : Tab 두번 눌러야 파일목록 출력되는데 숨김 파일까지 다 나온다

    - cd 디렉토리 이동(/home/ubuntu 로 이동할때)
        - zsh : cd /h/u 입력 후 Tab키로 자동완성 가능
        - bash : cd /home/ubuntu 입력

    - zsh가 편의성이 높다
    - Shell과 Kernel이 분리되어 있음으로써 사용자는 자기가 원하는 shell을 선택해 사용할 수 있다.

___

# **Shell Script**

root/bin 폴더에는 현재 리눅스에 깔려있는 프로그램들이 있다.
```
ls /bin
```
을 하면 볼 수 있음.

- 새로운 스크립트 작성

    ```
    nano backup
    ```
    ```js
    // In Nano Editor

    #!/bin/bash
    // 이 밑으로 입력되는 코드는 /bin/bash 프로그램으로 실행되어야한다.

    if ! [ -d bak ]; then 
    // 현재 디렉토리에 bak이라는 디렉토리가 존재하지 않으면,
        mkdir bak // 커맨드 실행
    fi // if문 종료
    cp *.log bak
    ```

    바로 backup을 실행하려면 Permission denied 에러가 뜨는데,

    ```
    chmod +x backup
    ```
    위 커맨드를 실행하면 backup 스크립트에 executable 권한이 주어진다.

    <img src="https://user-images.githubusercontent.com/66513003/129046805-ec7b3acd-3c5b-455c-8af7-7a239477b265.png" width="400">

- 스크립트 실행
    ```
    ./backup
    ```
- 스크립트 전문
    ```
    #!/bin/bash

    if ! [ -d bak ]; then
        echo "bak 폴더를 생성합니다."
        mkdir bak
    fi
    cp *.log bak
    echo "log파일 백업 완료."
    ```

___

## **alias**

- l이 ls -al로 동작한다.
    ```
    alias l='ls -al'
    ```

- c를 clear로
    ```
    alias c='clear'
    ```

ref: https://www.cyberciti.biz/tips/bash-aliases-mac-centos-linux-unix.html
___

## **Shell Startup Script**

쉘이 실행되면 특정한 스크립트가 실행되도록 설정하기

- .bashrc 파일에 적혀있는 명령어는 shell이 실행되면 자동으로 실행되는 명령어들이다.

    ```
    nano ~/.bashrc
    ```
    로 수정

    - .bashrc에서 $PATH 환경변수 설정이 가능

___
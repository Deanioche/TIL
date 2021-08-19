# **Linux Package Manager**

- linux terminal 에서의 앱스토어 같은 역할 (npm, pip 등...)

- `Package list`를 최신버전으로 업데이트
    ```js
    sudo apt-get update
    // upgrade와는 다르니 주의
    ```
    

- 패키지 검색
    ```
    sudo apt-cache search (패키지명)
    ```

- 모든 패키지 업데이트
    ```js
    sudo apt-get upgrade
    // update가 아님
    ```

- 패키지 삭제
    ```
    sudo apt-get remove (패키지명)
    sudo apt-get purge (패키지명) // 강력 - 환경설정 파일까지 날아감
    ```

___

### **Nano 편집기**

- 설치
    ```
    sudo apt-get install nano
    ```

___

### **htop 작업관리자**    
top은 리눅스에 기본으로 설치되어있는 작업관리자.  
htop은 시각적으로 개선된 버전.

- 설치
    ```
    sudo apt-get install htop
    ```

- 업데이트
    ```js
    sudo apt-get upgrade htop
    // update가 아님
    ```

- 실행
    ```
    sudo htop
    ```
    <img src="https://user-images.githubusercontent.com/66513003/128873151-cddaa290-66b6-4a84-9585-e56192626d2c.png" width="400">

___

### **git**

- 설치
    ```
    sudo apt-get install git
    ```

___

### **openssh**
    
    서버가 켜진 다른 컴퓨터에 접속해 원격 제어가 가능

- 설치
    ```
    sudo apt-get install openssh-server
    sudo apt-get install openssh-client
    ```

- 실행
    ```
    sudo service ssh start
    ```

클라이언트가 설치된 리눅스 기기로 서버가 켜진 다른 리눅스 기기의 ip를 입력해 접속하면 원격 제어가 된다.
    ```
    ssh -p (포트) surimi@(ip주소)
    ```

___

## **forever**
NodeJS 서버 백그라운드 실행

- 설치
    ```
    sudo npm install forever -g
    ```

- 실행
    ```
    sudo forever start server.js
    ```

- 동작중인 프로그램 리스트
    ```
    sudo forever list
    ```

- forever 종료
    ```
    sudo forever stop (pid)
    ```
    리스트에 뜨는 프로세스의 pid를 입력하면 된다.

___
# NodeJs in Linux

- 설치

    nodejs를 apt에서 바로 받으면 구버전이 설치된다.

    ```
    curl -sL https://deb.nodesource.com/setup_16.x | sudo -E bash - 

    sudo apt-get install -y nodejs
    ```
    위 순서대로 해줘야 최신버전이 깔린다.
    
    ```
    npm install -g npm@7.20.6
    ```
    그리고 npm 업데이트

___

- 리눅스 방화벽 포트 허용
    https://kibua20.tistory.com/124

___

- 접속 timeout 뜰때 확인할거

[link](https://okky.kr/article/1021878)

[link2](https://okky.kr/article/894862)

- 포트 확인
    ```
    sudo netstat -antp
    ```
- 포트 설정 초기화
    ```
    iptables -F
    ```

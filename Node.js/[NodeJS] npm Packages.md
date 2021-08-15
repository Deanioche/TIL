## npm packages

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
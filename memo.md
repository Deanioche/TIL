# memo

## **vscode 터미널 현재파일 경로로 이동시키는 단축키 설정**

keybindings.json에서
```json
{
    "key": "alt+`",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
        "text": "cd \"${fileDirname}\"\u000D"
    }
}
```
추가하면 알트 + ` 버튼으로 경로가 바뀜.

${fileDirname} : 파일 경로
\u000D : 엔터키 입력


## Github SSH 키로 접속하기

**git bash에서 **

- SSH키 생성
    ```
    ssh-keygen -t rsa -b 4096 -C "(이메일 주소)"
    ```
    빈칸으로 엔터 엔터 엔터

    /c/Users/(사용자 이름)/.ssh/id_rsa.pub에 ssh 키가 생성됨

- ssh-agent에 SSH키 추가
    ```
    $ eval $(ssh-agent -s)
    > Agent pid (pid넘버가 출력됨)
    ```

    ```
    $ ssh-add ~/.ssh/id_rsa
    ```

- github에 ssh키 등록하기

    <img src="https://user-images.githubusercontent.com/66513003/129449765-c58c704d-4ff0-41a3-b59f-c1dcff0dc4d2.png">

    Title에는 아무 이름

    Key에는 /c/Users/(사용자 이름)/.ssh/id_rsa.pub에 담긴 키를 복붙한다

- SSH로 Clone

    <img src="https://user-images.githubusercontent.com/66513003/129449840-4c7a3379-a7a7-4292-8afd-0d6815ed3265.png" width="400">

    SSH로 repository를 클론해주면 아이디/비밀번호 입력 없이 push가 가능하다.

___

- Git Bash에 Alias 영구 저장

    ```
    C:\Program Files\Git\etc\profile.d/aliases.sh
    ```
    에 저장할 alias 명령어 입력
# **Github memo**

## commit 한 author 수정

[ref_link](https://korband.tistory.com/34)

1. `git log` 명령어로 수정할 commit 찾기
2. 수정할 commit이 최신 commit부터 5번째라면, `git rebase -i HEAD~5`
3. rebase 할 commit이 5개가 잡히며 에디터가 열리는데, 수정할 commit을 pick -> e (edit)으로 수정하고 저장후 에디터 닫기.
4. `git commit --amend --author="Soksurim <briochefavori@gmail.com>"` 명령어로 author 수정
5. `git rebase --continue`로 진행하면,
    ```
    Successfully rebased and updated refs/heads/main.
    ```
    이라 뜨며 수정된 사항이 저장됨.

___

## **Github SSH 키로 접속하기**

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

## **Git Bash에 Alias 영구 저장**

    ```
    C:\Program Files\Git\etc\profile.d/aliases.sh
    ```
    에 저장할 alias 명령어 입력

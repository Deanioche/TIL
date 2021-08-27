## **vim 에디터 한글 깨짐 문제**


- 나의 vi 환경에서만 적용하기

    ```
    ~/.vimrc
    ```

- 전체 사용자의 vi 환경에서 적용하기

    ```
    /etc/vim/vimrc
    ```    

위 경로의 파일에 2 줄을 추가하면 된다.

```
set encoding=utf-8

set fileencodings=utf-8
```
# memo


## replaceAll 함수
- python
    replace()의 세번쨰 파라미터에 -1을 넣으면 모든 범위에서 replace 수행.
    ```py
    "ABACA".replace("A", "", -1) // BC
    ```

- JS
    JS는 replaceAll()함수가 2021년에 추가됨.
    ```js

    ```

- Java
    Java는 1.4버전부터 replaceAll()이 있음
    
    - replace()와 replaceAll()의 차이  
        replace(str, result)로 String형식을 받고,
        replaceAll(exp, result)로 정규표현식을 사용한다.
    ```java
    String ex = "/c\\=|c\\-|dz\\=|d\\-|lj|nj|s\\=|z\\=/g";

    System.out.println("ljes=njak".replaceAll(ex, " ").length());
    ```
___

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



___

- vscode indent (tab size) 설정

    - ctrl + , 설정에선 4인데 2칸만 건너뛴다?  
        -> vscode 우측 하단 파란 줄에 **Spaces:2** 확인하기

___
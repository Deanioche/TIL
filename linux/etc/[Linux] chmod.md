## **chmod**

```
chmod [option] [target]
```

- 현재 디렉토리의 전체 파일에 대해 권한 수정
    ```py
    chmod 000 ./*  ---------
    chmod 111 ./*  --x--x--x
    chmod 222 ./*  -w--w--w-
    chmod 333 ./*  -wx-wx-wx
    chmod 444 ./*  r--r--r--
    chmod 555 ./*  r-xr-xr-x
    chmod 666 ./*  rw-rw-rw-
    chmod 777 ./*  rwxrwxrwx
    ```

___

## **setUID 권한**

- 파일의 접근권한에서 **소유자의 실행 권한**에 x가 아닌 **s**가 표시됨.

- 실행 파일에 SetUID가 설정되어 있으면, 해당 파일이 실행될 때 ‘실행시킨 사용자’ 가 아닌 ‘파일의 소유자‘ 권한으로 실행됨.

- 일반 사용자가 passwd 명령으로 비밀번호를 수정하면 결국 /etc/passwd 또는 /etc/shadow 파일이 수정되어야 함(권한 상승이 필요함).

- 설정 방법은 chmod 4755 file 또는 chmod u+s file
- 해제 방법은 chmod 0755 file 또는 chmod u-s file


## **setGID 권한**

- 설정시, 접근권한에 그룹(g)의 실행 권한에 s가 표시됨

- setGID가 설정된 파일을 실행하면 '실행자의 그룹 권한'이 아닌 **파일 소유자의 그룹 권한**으로 실행된다.

- 디렉터리에 설정 된 경우, 그 디렉터리에 파일을 만들 때 '파일의 소유 그룹'이 **디렉터리의 소유 그룹**으로 지정된다.

- 설정 방법
    ```
    chmod 2661 [target]
    또는
    chmod g+s [target]
    ```

## **StickyBit**

- 파일의 접근권한에서 기타 사용자의 실행 권한에 t가 표시됨

- 주로 공유 디렉터리에 설정되며, 누구나 그 디렉터리에 파일 생성할 수 있지만 파일의 소유자만 삭제할 수 있음

- 설정 방법은 chmod 1755 file 또는 chmod o+t file
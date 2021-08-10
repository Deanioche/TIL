# **Linux**

## **명령어**
명령어 중간중간 옵션으로 -oo 붙이는건 `파라미터`라 부름

- `mkdir` : 디렉토리 생성
    - `-p, --parents` 를 붙이면 최종 폴더를 생성하기 위해 필요하면 그 부모 폴더도 함께 생성한다.
        ```
        mkdir -p dir1/dir2/dir3/dir4
        ```
        dir4 폴더를 생성할때 -p 옵션이 없으면 dir1~3이 없는 경우 에러가 발생.  
        하지만 해당 옵션이 있으면 dir1~dir3폴더를 생성한다.


- `pwd` : 현재 디렉토리
- `ls` : 현재 디렉토리 파일 보기
    - `-a` : 숨겨진 파일까지 모두 보기
        - 숨김파일들은 파일/폴더명 앞에 .이 붙는다 (.gitignore)
    - `-l` : 자세히 보기 (파일에 대한 추가 정보 출력)

    - `-S` : 파일 사이즈 기준 정렬
    
- `cd (폴더명)` 또는 .. : 디렉토리 이동 / ..은 뒤로가기
    - 폴더명 앞글자만 적고 Tab키로 자동완성 가능

- `clear` 터미널 초기화

- `rm (옵션) (파일명)` : 해당 파일 삭제
    - `-r` : 해당하는 디렉토리와 그 안의 파일까지 `모두 삭제`

- `touch (파일명)` : 파일 생성
- `vi (파일명)` : 파일 생성 후 vim 편집기 실행

- `cat (파일명)` : 파일 내용을 출력

- `cp (파일명) (디렉토리/새 파일명)` : 파일을 해당 디렉토리에 새 파일명을 지정해 복사
- `mv (파일명) (디렉토리/새 파일명)` : 파일을 해당 디렉토리에 새 파일명으로 이동 (파일명을 변경할때에도 사용한다.)

- `man (명령어)` : 명령어에 대한 메뉴얼 페이지로 이동 ( --help 보다 디테일한 설명)
    - 매뉴얼이 켜진 상태에서 특정 단어만 찾고싶을 때, '/sort' 입력
    - 특정 단어가 하이라이트 되면 N키로 다음 단어로 스크롤 이동 할 수 있다.
    - Q 키로 매뉴얼 빠져나감

- `sudo (super user do)` : 슈퍼유저 / 루트 권한을 사용
    - sudo apt-get install git : git 설치


## **파라미터**
- (명령어) --help : 해당 명령어에 대한 도움말
    ```
    root@goorm:/workspace/linux# rm --help
    사용법: rm [<옵션>]... [<파일>]...
    Remove (unlink) the FILE(s).

    -f, --force           ignore nonexistent files and arguments, never prompt
    -i                    prompt before every removal
    -I                    prompt once before removing more than three files, or
                            when removing recursively; less intrusive than -i,
                            while still giving protection against most mistakes
        --interactive[=WHEN]  prompt according to WHEN: never, once (-I), or
                            always (-i); without WHEN, prompt always
        --one-file-system  when removing a hierarchy recursively, skip any
                            directory that is on a file system different from
                            that of the corresponding command line argument
        --no-preserve-root  do not treat '/' specially
        --preserve-root   do not remove '/' (default)
    -r, -R, --recursive   remove directories and their contents recursively
    -d, --dir             remove empty directories
    -v, --verbose         explain what is being done
        --help     이 도움말을 표시하고 끝냅니다
        --version  버전 정보를 출력하고 끝냅니다
    ```


___

## **ls -l 파일 출력 정보**
```
파일권한      파일 소유자  크기  파일생성시간   파일이름
-rw-rw-r-- 1 root root    0  8월  8 05:46 empty_file.txt
drwxrwxr-x 2 root root 4096  8월  8 05:42 hello_linux
```
파일 권한 앞에 `d`가 붙어있으면 `directory`라는 뜻

___

## **Nano 편집기**

- 설치
    ```
    sudo apt-get install nano
    ```


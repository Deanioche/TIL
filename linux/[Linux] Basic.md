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
    - `cd ~`는 바로 홈 디렉토리로 보내준다.

- `clear` 터미널 초기화

- `rm (옵션) (파일명)` : 해당 파일 삭제
    - `-r` : 해당하는 디렉토리와 그 안의 파일까지 `모두 삭제`

- `touch (파일명)` : 파일 생성
- `vi (파일명)` : 파일 생성 후 vim 편집기 실행

- `cat (파일명)` : 파일 내용을 출력
    - `cat`만 실행시키면, 사용자가 키보드로 입력하는 정보를 받아 그대로 출력. Ctrl + D로 빠져나옴.

- `cp (파일명) (디렉토리/새 파일명)` : 파일을 해당 디렉토리에 새 파일명을 지정해 복사
- `mv (파일명) (디렉토리/새 파일명)` : 파일을 해당 디렉토리에 새 파일명으로 이동 (파일명을 변경할때에도 사용한다.)

- `man (명령어)` : 명령어에 대한 메뉴얼 페이지로 이동 ( --help 보다 디테일한 설명)
    - 매뉴얼이 켜진 상태에서 특정 단어만 찾고싶을 때, '/sort' 입력
    - 특정 단어가 하이라이트 되면 N키로 다음 단어로 스크롤 이동 할 수 있다.
    - Q 키로 매뉴얼 빠져나감

- `sudo (super user do)` : 슈퍼유저 / 루트 권한을 사용
    - sudo apt-get install git : git 설치

- `grep (찾으려는 단어) (파일명)` : 파일에서 지정한 단어가 포함된 행만을 화면에 표시

- `ps` : 현재 실행되고 있는 프로세스 출력

- `head` (파일명) : 파일의 앞 10줄만 출력
    - `-n`(줄 수) : 줄 수 만큼만 출력
        ```js
        head -n2 linux.txt
        // linux.txt 파일의 첫 두 줄만 출력
        ```

- `whereis (프로그램 이름)` : 프로그램이 설치되어있는 위치를 출력
    ```
    # whereis htop
    htop: /usr/bin/htop
    ```

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


## **파일 다운로드**

```
wget -O (파일명 지정) (파일 url)
```

___

## **git 소스코드 다운로드**

깃 설치 후
```
git clone http://github.com/facebook/react.git react_src
```
react_src 디렉토리에 해당 git url의 오픈소스가 다운로드 됨

___

## **GUI vs CLI**

- graphical user interface
    - 가독성, 사용성 높음
    - 배우기는 쉽지만 작업의 자동화가 힘듬

- Command Line Interface
    - 커맨드라인으로만 이루어져 있기 때문에 CPU, 메모리 자원을 적게 먹음
    - heavy한 작업에 쓰임

___

## Sequence Execution

여러 커맨드를 ;로 구분해서 입력하면 커맨드 동작이 하나하나 완료되며 순차적으로 실행됨.  
```js
pwd;mkdir why;cd why;pwd
// 실행 결과
/workspace/linux/why
/workspace/linux/why/why
```

___

## Pipeline

한 커맨드의 실행 결과를 다른 커맨드의 입력으로 주기.

- ls의 도움말에서 sort가 포함된 행만 찾아서 또 그 안에서 file이 포함된 행을 출력
    ```
    ls --help | grep sort | grep file
    ```

- 실행중인 프로세스에서 이름에 bash가 포함된 프로세스만 출력
    ```
    ps aux | grep bash
    ```

___

## Linux file system structure

### **1. / – Root**
Every single file and directory starts from the root directory.
Only root user has write privilege under this directory.
Please note that /root is root user’s home directory, which is not same as /.

### **2. /bin – User Binaries**
Contains binary executables.
Common linux commands you need to use in single-user modes are located under this directory.
Commands used by all the users of the system are located here.
For example: ps, ls, ping, grep, cp.

### **3. /sbin – System Binaries**
Just like /bin, /sbin also contains binary executables.
But, the linux commands located under this directory are used typically by system aministrator, for system maintenance purpose.
For example: iptables, reboot, fdisk, ifconfig, swapon

### **4. /etc – Configuration Files**
Contains configuration files required by all programs.
This also contains startup and shutdown shell scripts used to start/stop individual programs.
For example: /etc/resolv.conf, /etc/logrotate.conf

### **5. /dev – Device Files**
Contains device files.
These include terminal devices, usb, or any device attached to the system.
For example: /dev/tty1, /dev/usbmon0

### **6. /proc – Process Information**
Contains information about system process.
This is a pseudo filesystem contains information about running process. For example: /proc/{pid} directory contains information about the process with that particular pid.
This is a virtual filesystem with text information about system resources. For example: /proc/uptime

### **7. /var – Variable Files**
var stands for variable files.
Content of the files that are expected to grow can be found under this directory.
This includes — system log files (/var/log); packages and database files (/var/lib); emails (/var/mail); print queues (/var/spool); lock files (/var/lock); temp files needed across reboots (/var/tmp);

### **8. /tmp – Temporary Files**
Directory that contains temporary files created by system and users.
Files under this directory are deleted when system is rebooted.

### **9. /usr – User Programs**
Contains binaries, libraries, documentation, and source-code for second level programs.
/usr/bin contains binary files for user programs. If you can’t find a user binary under /bin, look under /usr/bin. For example: at, awk, cc, less, scp
/usr/sbin contains binary files for system administrators. If you can’t find a system binary under /sbin, look under /usr/sbin. For example: atd, cron, sshd, useradd, userdel
/usr/lib contains libraries for /usr/bin and /usr/sbin
/usr/local contains users programs that you install from source. For example, when you install apache from source, it goes under /usr/local/apache2

### **10. /home – Home Directories**
Home directories for all users to store their personal files.
For example: /home/john, /home/nikita

### **11. /boot – Boot Loader Files**
Contains boot loader related files.
Kernel initrd, vmlinux, grub files are located under /boot
For example: initrd.img-2.6.32-24-generic, vmlinuz-2.6.32-24-generic

### **12. /lib – System Libraries**
Contains library files that supports the binaries located under /bin and /sbin
Library filenames are either ld* or lib*.so.*
For example: ld-2.11.1.so, libncurses.so.5.7

### **13. /opt – Optional add-on Applications**
opt stands for optional.
Contains add-on applications from individual vendors.
add-on applications should be installed under either /opt/ or /opt/ sub-directory.

### **14. /mnt – Mount Directory**
Temporary mount directory where sysadmins can mount filesystems.

### **15. /media – Removable Media Devices**
Temporary mount directory for removable devices.
For examples, /media/cdrom for CD-ROM; /media/floppy for floppy drives; /media/cdrecorder for CD writer

### **16. /srv – Service Data**
srv stands for service.
Contains server specific services related data.
For example, /srv/cvs contains CVS related data.

ref : https://www.thegeekstuff.com/2010/09/linux-file-system-structure/

____

## **파일 찾기**

- locate
    ```
    locate (파일명)
    ```

    locate 명령어는 디렉토리를 뒤지는게 아닌, 데이터베이스를 뒤진다.

- find
    ```js
    find (위치) -name (파일명)

    sudo find / -name *.log // root폴더부터 하위폴더까지 범위에서 확장자가 .log인 파일을 찾는다. root폴더는 super user 권한이 있어야 됨.

    find ~ -name *.log // home 디렉토리부터 찾기.

    // 조건에 맞는 '파일'만 찾기 (폴더는 제외됨)
    find ~ -type f -name *.log

    // 현재 폴더 이하에서 실행가능한 파일 검색
    find ./ -perm /a=x

    // 빈 파일만 찾기
    find ./ -type f -empty
    find ./ -type d -empty // 폴더

    // ./bak 폴더 안의 *.log인 파일 모두 삭제
    find ./bak/ -type f -name "*.log" -exec rm -f {} \;

    // 숨김 파일 찾기
    find ./ -type f -name ".*"

    // 최근 50일 안에 수정된 파일 검색
    find / -mtime 50
    find / -mtime +50 –mtime -100 // 50일 ~ 100일 사이

    // 최근 1시간 안에 변경된 파일 검색
    find / -cmin -60

    // 50 ~ 100MB 사이 파일 검색
    find / -size +50M -size -100M

    // 특정 파일 검색 후 삭제
    find / -type f -name *.mp3 -size +10M -exec rm {} \; // 10메가 이상 mp3파일
    ```

    ref : https://www.tecmint.com/35-practical-examples-of-linux-find-command/

- whereis

    실행파일의 위치를 찾아줌

___

## **$PATH**

ls나 rm 등 /bin 폴더에 있는 프로그램을 어느 디렉토리에서나 사용할 수 있는 이유는, $PATH에 /bin폴더가 등록되어있기 때문이다. 이를 `환경변수`라 한다.

```
echo $PATH
```
위 명령어를 실행하면 등록되어있는 경로가 출력된다.

___

## **Background execute**

프로그램 실행 중, Ctrl + z 키를 누르면 실행중이던 프로그램은 background로 들어가고 디렉토리 화면으로 돌아온다

그리고 fg 명령어를 입력하면 다시 실행중이던 프로그램으로 돌아온다.

- 현재 backgound에서 동작중인 프로그램 보기
    ```js
    # jobs

    root@goorm:/workspace/linux# jobs
    [1]   정지됨               nano
    [2]   정지됨               vim
    [3]-  정지됨               nano
    [4]+  정지됨               htop

    // +는 fg명령어 입력시 foreground로 돌아올 프로그램
    // -는 그 다음 프로그램
    ```

- 원하는 프로그램을 선택해 실행하고 싶으면 `fg %(프로그램 번호)`를 입력하면 된다.
    ```js
    fg %2 //vim 실행
    fg %1 //nano 실행
    ```

- 프로그램 종료
    ```js
    kill %2 //vim 종료
    kill %1 //nano 종료

    // 위 명령어로 종료가 안되면

    kill -9 %1 //강력
    ```

- 프로그램을 바로 백그라운드로 실행
    ```js
    ls -alR / > result.txt 2> error.log & // 대충 동작이 오래걸리는 명령어
    // 명령어 & 앰퍼센드를 뒤에 입력하면 백그라운드에서 동작해서
    // 바로 다음 명령어를 입력할 수 있다.
    // 동작이 끝나면 [n] Exit 1 이라고 뜬다.
    ```

___

## **Daemon**

Daemon 프로그램들은 항상 실행되고 있다는 특성을 가지고있다.

언제 사용할지 알수 없기 때문에 (Server 등)

- Daemon 프로그램들이 위치하는 디렉토리
    ```
    /etc/init.d
    ```

- apache 설치 후 실행
    ```js
    // 설치
    sudo apt-get install apache2
    
    // 실행
    sudo service apache2 start

    // 실행중 여부 확인
    ps aux | grep apache2

    // 종료
    sudo service apache2 stop
    ```
    Daemon으로써 실행되는 모든 프로그램은 start / stop 명령어가 존재

- 리눅스 실행시 자동으로 실행되게 하기
    
    `/etc` 경로에는 rc~로 시작하는 디렉토리가 있는데, `rc3.d`는 `CLI`방식일 때, `rc5.d`는 `GUI` 방식일 때 사용된다.

    rc3.d 디렉토리에 들어가면 `../init.d/apache2`가 들어가있는걸 볼 수 있다.

    ```js
    lrwxrwxrwx 1 root root 17  8월 12 04:37 S01apache2 -> ../init.d/apache2

    // 맨 앞의 l은 링크라는 뜻 (바로가기)
    // 바로가기 이름이 S로 시작하면 리눅스 부팅시 실행되는 프로그램
    // K면 실행되지 않는 프로그램
    // S뒤에 01, 02는 실행 우선순위

    // etc/rc3.d/ 디렉토리의 S01apache2라는 이름의 바로가기는 리눅스가 CLI방식(rc3.d)으로 구동되었을때 ../init.d/apache2 프로그램이 자동으로 실행되게 한다.
    ```

    - 리눅스 부팅시 프로그램이 자동으로 실행되게 하려면 CLI 부팅 기준, etc/rc3.d 디렉토리에 해당 프로그램의 `링크`를 걸면 된다.

___

## **CRON**

정기적으로 프로그램을 실행시켜줌.
ref : https://tecadmin.net/crontab-in-linux-with-20-examples-of-cron-schedule/

- 크론 에디터 열기
    ```
    crontab -e
    ```

- 동작 주기 설정
    ```js
    m h dom mon dow command

    // 분
    10 // 매시간 10분
    */1 // 1분에 한번

    // 시
    * // 시간과 상관없이

    // 일 dom
    24 // 매달 24일

    ...
    ```

    <img src="https://user-images.githubusercontent.com/66513003/129143475-39a37e8d-0a69-403b-95bf-cbabac2d7ecd.png" width="400">

    - 1분마다 현재시간을 로그에 기록
        ```
        */1 * * * * date >> date.log 2>&1
        ```
        2>&1 는 에러를 Standard Output으로 바꿔 date.log에 함께 저장되게 한다.

- 동작하는 cron 목록 보기
    ```
    crontab -l
    ```

- 동작되는지 감시 (tail)
    ```
    tail -f date.log
    ```
    date.log를 감시하다가 파일이 수정되면 자동 리프레시

___

## **Multi User**

- `id` : 현재 사용중인 계정 정보
- `who` : 현재 접속중인 계정 리스트
## **magic file**

___


## **file**

파일의 종류를 출력하는 기능

```
file [target file]
```

- 디렉토리를 넣으면 123: directory 출력

```
123/  magic.mgc  my-magic  test.23  test.html  test.js  test.php
```
현재 디렉토리에 위와 같이 파일이 있다고 했을 때, file 명령어를 실행하면

```py
surimi@surimi:~/dev/magic$ file *
123:       directory
magic.mgc: magic binary file for file(1) cmd (version 14) (little endian)
my-magic:  ASCII text
test.23:   ASCII text
test.html: HTML document, ASCII text
test.js:   ASCII text
test.php:  PHP script, ASCII text
```

- file -i 옵션 추가
    ```py
    surimi@surimi:~/dev/magic$ file -i *
    123:       inode/directory; charset=binary
    magic.mgc: application/octet-stream; charset=binary
    my-magic:  text/plain; charset=us-ascii
    test.23:   text/plain; charset=us-ascii
    test.html: text/html; charset=us-ascii
    test.js:   text/plain; charset=us-ascii
    test.php:  text/x-php; charset=us-ascii
    ```

- magic 파일을 별도로 설정해 사용하기

폴더에 my-magic 파일을 생성해 다음과 같이 저장.
```
0 search/16 23 File containing "23"
!:mime text/x-23
```
위 명령어의 의미는
파일 내에서 "23"이란 숫자를 찾으면  
해당 파일의 type으로 "text/x-23"를 출력하는 magic 파일이다.

그리고 -m 옵션으로 magic 파일을 지정해 실행하면,  

```py
surimi@surimi:~/dev/magic$ file -m my-magic *
123:       directory
magic.mgc: data
my-magic:  File containing "23", ASCII text
test.23:   File containing "23", ASCII text
test.html: ASCII text
test.js:   ASCII text
test.php:  ASCII text
```

```py
surimi@surimi:~/dev/magic$ file -im my-magic *
123:       inode/directory; charset=binary
magic.mgc: application/octet-stream; charset=binary
my-magic:  text/x-23; charset=us-ascii
test.23:   text/x-23; charset=us-ascii
test.html: text/plain; charset=us-ascii
test.js:   text/plain; charset=us-ascii
test.php:  text/plain; charset=us-ascii
```

___

## **magic 파일을 컴파일 하기**

작성한 magic 파일을 binary 형식으로 컴파일 해 사용하면 처리 속도를 높일 수 있다.

```
$ file -C -m my-magic
```
위 명령어로 my-magic 파일을 컴파일.  
my-magic.mgc 파일이 생성된다.

```
surimi@surimi:~/dev/magic$ file -m my-magic.mgc *
123:          directory
my-magic:     File containing "23", ASCII text
my-magic.mgc: data
test.23:      File containing "23", ASCII text
test.html:    ASCII text
test.js:      ASCII text
test.php:     ASCII text

surimi@surimi:~/dev/magic$ file -im my-magic.mgc *
123:          inode/directory; charset=binary
my-magic:     text/x-23; charset=us-ascii
my-magic.mgc: application/octet-stream; charset=binary
test.23:      text/x-23; charset=us-ascii
test.html:    text/plain; charset=us-ascii
test.js:      text/plain; charset=us-ascii
test.php:     text/plain; charset=us-ascii
```

## **여러 매직 파일 넘기기**

':'를 이용해 여러 매직 파일을 지정할 수 있다.

```
$ file -i -m my-magic.mgc:/usr/share/misc/magic.mgc test.*
test.23:   text/x-23; charset=us-ascii
test.foo:  text/x-php; charset=us-ascii
test.html: text/html; charset=us-ascii
```


## 파일 찾기

___

## **locate**

```
locate [options] pattern
```

![image](https://user-images.githubusercontent.com/66513003/132127685-3392fb84-fdb0-43a2-b932-7cf1083b4eff.png

___

## **find**

```
find [pathnames] [expression]
```

![image](https://user-images.githubusercontent.com/66513003/132127859-af768875-cf16-43bd-b8a1-0d040114cbc1.png)



```
find -name bin 2> /dev/null
```

파일 이름이 정확하게 "bin"인 것만 찾음.  
표준 오류 출력으로 뜨는 오류메세지는 화면에 출력하지 않고 쓰레기통으로. 


## **find 명령에서 조건 지정**

![image](https://user-images.githubusercontent.com/66513003/132128027-0d475b47-0278-41cd-b932-54d848589c3d.png)

```
find -cmin -8 : 수정된지 8분 이내의 파일 출력
find -cmin +8 : 수정된지 8분이 지난 파일 출력
```

## **find 명령후 액션**

![image](https://user-images.githubusercontent.com/66513003/132128232-e8864532-94d7-41eb-8fe2-e8397bc178db.png)


## **find 명령 사용 예**

```js
find /usr/share -size +10M
find /data -size +500M -size -5G -exec du ´{}´ \;
find . -type f -exec file {} \;

find /home -user chris –ls  // 소유자가 chris인 파일/ 디렉토리

find /home -user chris -or -group staff –ls // 소유자가 chris 이거나 staff 그룹인 파일/ 디렉토리

find /bin -perm 755 // 접근 권한이 8진법으로 755인 파일/ 디렉토리

find /home/chris/ -perm -444 -type d –ls 
// -444는 소유자, 그룹, 기타에 대해서 모두 read 권한을 가질 때. 
// +444는 셋 중 하나라도 read 권한을 가지는 것. 
// 아무것도 없이 444는 정확하게 444인 파일만 출력.

find /bin /usr/bin /sbin /usr/sbin –ctime –3
// /bin과 /usr/bin과 /sbin과 /usr/sbin
// 위 4개의 폴더에서 수정된지 3일 이내의 파일을 출력.

find ~ \( -type f -not -perm 0600 \) -or \( -type d -not
-perm 0700 \)
// 접근 권한이 0600, 0700이 아닌 "파일"
```
___

## **grep**

파일에서 지정된 문자열 패턴을 포함한 라인을 찾아 출력하는 기능

- 파이프(|)를 사용하여 앞 명령의 결과(검색된 파일)를 입력으로 받아 검색할 때 grep을 사용.

```
grep [options] patern [files]
```
pattern은 찾으려는 문자열이며 정규식으로 표현 가능

- 옵션
    - -r 옵션을 붙이면 파일 대신 디렉터리를 지정해 줄수 있는데, 그러면 해당 디렉터리에 속해있는 모든 파일을 대상으로 검색을 수행.
    - -i는 대소문자를 구분하지 않음
    - -v는 반대로 매칭이 일어나지 않은 라인을 출력함. (제외 검색)

- 예
    - grep root /etc/passwd
    - grep -n unix ~/*.txt
    - ip addr show | grep inet
    - grep -r printf ~/dev/c/
        - ~/dev/c/ 경로의 모든 파일에서 printf 검색.
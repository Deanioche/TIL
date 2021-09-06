## **파일 압축**

___

## **gzip 명령**
 
gzip은 압축 파일의 형식이자 파일의 압축과 해제를 위한 프로그램
- 가장 널리 사용되는 리눅스 압축 프로그램
- 초기 Unix 시스템의 압축 프로그램을 GNU 프로젝트에서 수정한 버전

```
gzip [options] [files]
```

- 압축시 원본 파일은 .gz 확장자를 갖는 파일로 대체됨
- gzip file을 수행하면 file은 없어지고 file.gz이 만들어짐

- 옵션
![image](https://user-images.githubusercontent.com/66513003/132189294-bba04535-7c4e-42f9-acdc-a0360c05e1be.png)

___

## **gunzip 명령**

.gz, .Z, .tgz, .taz 등의 확장자를 가진 압축파일을 풀고 확장자를 제거함  
(.tgz은 .tar.gz, .taz는 .tar.Z을 의미)

**gzip과 gunzip 명령의 사용 예**

![image](https://user-images.githubusercontent.com/66513003/132189740-2d8e570e-3454-449f-bb17-9c008aa0ab0f.png)

___

## **bzip2 명령**

**블록 정렬 압축 알고리즘**을 사용한 파일 압축 프로그램

gzip과 유사하나 압축 효율이 매우 좋음(압축 속도는 느림)
- 압축 후 파일 크기가 매우 작아짐(큰 파일에 사용하면 좋음)

사용법은 gzip과 유사하며 압축 파일의 확장자로 .bz2를 사용
- bzip2 file은 원본 파일을 없애고 file.bz2를 만듦
- bzip2 -k file는 원본 파일을 보존함
- bzip2 -d file.bz2은 bunzip2 file.bz2과 같음
- bunzip2 -c file.bz2는 bzcat file.bz2와 같음

___

## **tar 명령**

여러 파일을 하나의 아카이브 파일로 묶거나 아카이브 파일에서 파일을 추출하는 명령

아카이브는 백업 등의 목적으로 여러 파일을 하나로 묶은 것
```
tar mode [options] [tarfile] [pathnames...]
```
- tarfile 은 아카이브를 의미
- pathname 은 아카이브에 넣을 파일이나 디렉터리
- 아카이브 파일의 확장자는 보통 .tar를 사용함
- 모드나 옵션을 사용할 때 대시(-)를 사용하지 않는 편임

**모드**
- A는 tar 파일을 아카이브에 추가
- c는 새로운 아카이브의 생성
- x는 아카이브로부터 파일을 추출
- r은 아카이브에 파일을 추가
- t는 아카이브에 포함된 파일의 목록을 출력

**옵션**
- f는 아카이브 파일을 지정
- v는 처리 과정에서 대상 파일을 보여줌
- z는tar 명령에서gzip을사용(.tar.gz)
- j는tar 명령에서bzip2를사용(.tar.bz2)

**tar 명령의 사용 예**

![image](https://user-images.githubusercontent.com/66513003/132190165-8f11b2f6-b132-4f18-afee-640f05dbd71e.png)
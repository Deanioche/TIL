## **vim editor**

___

- ## **커서 이동**
    <img src="https://user-images.githubusercontent.com/66513003/132123289-58959640-846f-4f1a-9ebe-d6b63939ca1e.png">

- ## **삭제**
    <img src="https://user-images.githubusercontent.com/66513003/132123361-d099c864-8482-48f8-bb72-ff9eeacc8759.png">

- ## **수정 모드**
    <img src="https://user-images.githubusercontent.com/66513003/132123470-3704806b-0b8d-4e76-a28e-0ae0831602ff.png">


- ## **복사 붙여넣기 (yank & Paste)**
    <img src="https://user-images.githubusercontent.com/66513003/132123484-16fdad7d-d0b8-4198-86e4-6b36825c0de2.png">

- ## **블록 지정하기**
    드래그 효과.  
    드래그 해서 yank & Paste 가능.  
    <img src="https://user-images.githubusercontent.com/66513003/132125472-b7d062d8-1990-4aba-9840-7f163badd323.png">

- ## **기타 명령**

    <img src="https://user-images.githubusercontent.com/66513003/132125669-0aea4774-88cb-4e9d-8315-c34cd5eb051f.png">

- ## **검색 명령**

    ![image](https://user-images.githubusercontent.com/66513003/132125758-f6d26aa1-c485-4d6b-920a-caba2db804e0.png)

- ## **검색 명령(2)**

    ![image](https://user-images.githubusercontent.com/66513003/132126789-b2db44e2-c584-432c-ba8d-64a7360f25f7.png)

- ## **검색과 대치**

    ![image](https://user-images.githubusercontent.com/66513003/132126951-361ea9f0-b851-4503-a37c-288ad76ac755.png)

    - :%s/num/number 는 각각의 라인에서 첫번째로 등장하는 "num"만 변경.  
    - :%s/num/number/g 문서에 존재하는 모든 "num"을 변경.  
    - :1,&s/num/number/g 문서의 1번 라인 ~ 끝까지의 범위에서 변경.
    - :1,10s/~/~/g 1번 ~ 10번 라인 범위 내에서 변경.


___

## **여러 파일의 내용을 일괄 변경 하는 법**

- 작업하려는 파일을 동시에 불러오기

```
vi a*.txt            
# 파일명들이 a1.txt, a2.txt 같이 공통되는 부분이 있는경우
```

vi에 접속 한 뒤 명령어 입력
```
:argdo %s/str/rep/g | update     # 일괄 변경
:wq                # 저장 후 종료
```

___

## **입력한 문자열을 똑같이 n번 추가 입력**

vi 편집기의 명령모드에서 반복 횟수를 입력 후 i로 입력모드로 전환.
입력 후 ESC를 누르면 입력환 횟수 - 1만큼 추가로 입력된다.

5 입력후 i로 "텍스트 내용 (엔터)" 입력 후 ESC누르면
```
"텍스트 내용"
"텍스트 내용"
"텍스트 내용"
"텍스트 내용"
"텍스트 내용"
```
가 된다.


___

## **vim 자동완성 기능**

https://johngrib.github.io/wiki/vim-auto-completion/

- ctrl p, n : 키워드 자동 완성
- ctrl x + ctrl f : 문장 자동 완성
- 
# Java Error Memo

## **Java 11 or more recent is required**

- 에러 전문
    ```
    Java 11 or more recent is required to run the Java extension. Please download and install a recent JDK. You can still compile your projects with older JDKs by configuring 'java.configuration.runtimes'
    ```

[**solution_link**](https://urakasumi.tistory.com/257)

___


## **error: unmappable character (0xEC) for encoding x-windows-949**

- 에러 전문 
    ```
    Hello.java:5: error: unmappable character (0xEC) for encoding x-windows-949
        //?옉?꽦?옄 : Yang
    ```

자바 컴파일러의 인코딩 방식으로 한글 문자를 읽지 못해 발생하는 문제

터미널에서 javac 컴파일 시, 뒤에 -encoding utf-8를 붙여주면 된다.

___


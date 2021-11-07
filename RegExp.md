# **RegExp 정규표현식**


- match
    ```
    2021-04-26           [0-9]{4}-[0-9]{2}-[0-9]{2}
    1a2b3c               ([0-9][a-z])+
    praesto20@gmail.com [\w]+@[\w]+.[\w]+
    한글 두 글자         [ㄱ-힣]{2} [ㄱ-힣] [ㄱ-힣]{2}
    주석 //              ^[//]{2}

    ^[0-9]*$	                            숫자
    ^[a-zA-Z]*$	                            영문자
    ^[가-힣]*$	                             한글
    \\w+@\\w+\\.\\w+(\\.\\w+)?	            E-Mail
    ^\d{2,3}-\d{3,4}-\d{4}$	                전화번호
    ^01(?:0|1|[6-9])-(?:\d{3}|\d{4})-\d{4}$	휴대전화번호
    \d{6} \- [1-4]\d{6}	                    주민등록번호
    ^\d{3}-\d{2}$                           우편번호
    ``` 

\d: 숫자인 경우, [0 - 9]와 같다
\D: 숫자가 아닌 경우, [^ 0 - 9] 와 같다.
\s: 공백 문자인 경우.띄어쓰기나, 탭(\t), 새로운 줄(\n, \r)인 경우
\S: 공백 문자가 아닌 경우
\w: 숫자 및 알파벳 문자인 경우. [a - zA - Z0 -9_] 와 같다
\W: 숫자 및 알파벳 문자가 아닌 경우. [^ a - zA - Z0 -9_] 와 같다


/c\=|c\-|dz\=|d\-|lj|nj|s\=|z\=/g
___

## **python**

https://ponyozzang.tistory.com/279
https://wikidocs.net/4308

```py
print(re.match('(\d[a-z])*', '1a2b3c').group()) // 1a2b3c
```
___

## **JS**

[ref_docs](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/replaceAll)

[ref_blog](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sambak99&logNo=90175483328)

```js
console.log('1a2b3c'.match('([0-9][a-z])*')) // 1a2b3c

let str = 'apple, Banana, orange, banana';
let replaced_str = str.replace(/banana/gi, 'tomato');

// 변경 전 : apple, Banana, orange, banana
// 변경 후 : apple, tomato, orange, tomato
```
변경 전 : apple, Banana, orange, banana
변경 후 : apple, tomato, orange, tomato

___

## **java**

https://coding-factory.tistory.com/529

https://codechacha.com/ko/java-regex/

[ref_docs replaceAll 항목](https://docs.oracle.com/javase/7/docs/api/java/lang/String.html)

```java
// BOJ 2941 중에서
String ex = "c=|c-|dz=|d-|lj|nj|s=|z=";
System.out.println("ljes=njak".replaceAll(ex, "_"));
```
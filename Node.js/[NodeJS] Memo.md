**Node.js**

___

- 한글 깨짐
    ```js
    res.writeHead(200, {'Content-Type': 'text/html;charset=UTF-8'});
    ```
___

## **\[npm\]**

- global & local 설치

    `-g`를 붙이면 global 안붙이면 local.  
    global로 설정하면 해당 컴퓨터 전역에서 사용할 수 있는 독립적인 소프트웨어로 설치가 된다.
    local로 설정하면 해당 패키지의 프로젝트 안에서만 사용이 가능. 

#

- uglifyjs
    - 작성한 소스코드를 못생기게 만듬

    - 기본
    ```js
    // 원문
    function alert(message) {
        console.log(message);
    }
    let myName = 'Kim';
    let myAge = 10;
    alert(`Hi, I'm ${myName}, ${myAge} yrs old`);

    //terminal
    uglifyjs test.js

    // 결과
    function alert(message){console.log(message)}let myName="Kim";let myAge=10;alert(`Hi, I'm ${myName}, ${myAge} yrs old`);
    ```

    - 옵션
    ```js
    // 변수명을 간단하게 변경
    uglifyjs test.js -m

    // 결과
    function alert(e){console.log(e)}let myName="Kim";let myAge=10;alert(`Hi, I'm ${myName}, ${myAge} yrs old`);

    // uglify를 적용한 결과를 파일(test.min.js)로 저장
    uglifyjs test.js -o test.min.js -m 
    ```
    
    






- nodemon
    - nodemon 은 코드 수정 후 서버를 수동으로 재시작 하지 않아도 바로 반영되게 해줌.

    ```
    npm install -g nodemon
    ```
    `-g`는 현재 폴더 뿐만 아니라 다른 작업 폴더에서도 쓸 수 있게 해줌.(global)
    
    - 보안 오류가 뜨는 경우

    Windows Powershell 관리자 권한 실행 
    ```
    > executionpolicy
    -> Resticted 라고 뜨면

    > set-executionpolicy unrestricted
    ```        
   <img src="https://user-images.githubusercontent.com/66513003/125573131-c3664efd-75aa-4a14-b383-70c314d4b559.png" width="400">

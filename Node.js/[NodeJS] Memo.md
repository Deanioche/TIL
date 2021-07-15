**Node.js**

___

- 한글 깨짐
    ```js
    res.writeHead(200, {'Content-Type': 'text/html;charset=UTF-8'});
    ```

- 동기 & 비동기
    ```js
    fs.readFile(), fs.readFileSync() 
    ```
    - Sync가 있으면 `동기`, 없으면 `비동기` 방식

    - 차이
    ```js
    //Sync 동기
    console.log(1);
    var data = fs.readFileSync(__dirname + '/index.html', { encoding: 'utf8' });
    console.log(data);
    console.log(2);

    // console.log(1)으로 1이 출력된 후  
    // fs.readFileSync 함수가 완전히 실행 된 뒤
    // console.log(2) 2가 출력됨

    // 동기방식은 전 코드의 실행이 끝나기 전엔 다음 코드로 넘어가지 않는다.

    // Async 비동기
    console.log(1);
    fs.readFile(__dirname + '/index.html', { encoding: 'utf8' }, (err, data) => {
        console.log(data);
    });
    console.log(2);
    // 1이 출력되고
    // fs.readFile 함수가 호출되고
    // 2가 출력되고
    // fs.readFile의 호출 결과인 index.html의 data가 출력된다.

    // 비동기 방식은 일단 코드들을 `호출`만 하고 결과가 돌아오는 순서대로 화면에 출력된다.
    ```
    
___

## **\[npm\]**
- https://www.npmjs.com/

- 사용법
    terminal에서 모듈을 설치하려는 경로로 이동 후 
    ```
    npm init
    ```
    을 입력해 패키지 설정 파일(package.json)을 생성한다.

- 모듈 설치할때 global & local 설정

    ```
    npm install uglifiyjs -g
    ```

    `-g`를 붙이면 global 안붙이면 local.  
    global로 설정하면 해당 컴퓨터 전역에서 사용할 수 있는 독립적인 소프트웨어로 설치가 된다.
    local로 설정하면 해당 패키지의 프로젝트 안에서만 사용이 가능. 

- 설치할 모듈을 자동으로 package.json의 dependencies에 등록하기
    ```
    npm install underscore --save
    ```
    `--save`를 추가한다.
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
    
#

- underscore

    - underscore는 자바스크립트 함수의 빈약한 부분을 채워준다  
    - 참조 : https://underscorejs.org/#first
    ```
    npm i underscore
    ```
    - unserscore 모듈 import
    ```js
    var _ = require('underscore');
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

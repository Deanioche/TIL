# 즉시 실행 함수

```js
//아래 함수선언문은 아무것도 반환하지 않는다(혹은 undefined)
function() {} 

//이런 표현식을 쓰면 !undefined는 true를 반환한다. 그리고 바로 실행하기도 함.
!function() {}()

//함수 실행의 결과로 실제 반환되는 값을 얻으려면
(function(){})();

//익명 즉시실행함수(더글러스 클락포드 권장표기법)
(function() {}());

const abc = function (a, b) {
    // 자릿수 맞추기
    console.log("1".padStart(3, "0")) // 001
    console.log("1".padEnd(4, "0")) // 1000
    console.log(a, b); // 123 456

}(123, 456); // 뒤에 ()를 붙이는 건 함수 선언과 동시에 실행시키는 것.
```



___
**JS 정리**

**# 호이스팅**
- 변수, 함수의 `선언`은 컴파일 단계에서 메모리에 저장됨.
- 최우선순위로 처리되므로, 코드상에서 나중에 선언되는 변수도 앞선 연산에 사용이 가능.
- 초기화가 아니므로 해당 변수는 선언만 된 상태로, `값`은 코드상의 순서대로 입력됨. (초기화 되기 전에는 undefined로 출력된다.)

    ```js
    num = 6;
    num + 7;
    var num;
    /* num이 선언되지 않더라도 에러를 내지 않습니다 */

    var x = 1; // x 초기화
    console.log(x + " " + y); // '1 undefined'
    var y = 2;

    // 아래 코드는 이전 코드와 같은 방식으로 동작합니다.
    var x = 1; // Initialize x
    var y; // Declare y
    console.log(x + " " + y); // '1 undefined'
    y = 2; // Initialize y
    ```

- 호이스팅 때문에 코드의 구조가 엉성해질 수 있어, `함수 표현식` 형태의 사용이 권장됨.

    ```js
    // plus(2, 3) - ReferenceError: Cannot access 'plus' before initialization

    // # 함수 표현식 형태
    const plus = function(x, y){
        return console.log(x + y)
    }

    plus(3, 4) // 7

    // # 함수 선언문 형태 (코드 전 후 상관없이 사용 가능.)
    function minus(x, y){
        return console.log(x - y)
    }
    ```

ref : https://developer.mozilla.org/ko/docs/Glossary/Hoisting
___


**# 자료형**

- Boolean
    - new Boolean 과 Boolean 차이
        ```js
        const a = new Boolean(false) // new Boolean 생성자 함수를 통한 객체 생성
        console.log(a, typeof a) // [Boolean: false] object

        if(a){ // false 인데 if 조건 만족
            console.log('a : false')
        }

        const b = Boolean(false) // Boolean 객체 생성
        console.log(b, typeof b); // false boolean

        if(b){ // x
            console.log('b : false')
        }else if(!b){ // false 로써 동작
            console.log('b : true')
        }
        ```

- Null & Undefined

    ```js
    const a = null;
    console.log(a, typeof a) // null object

    let b;
    console.log(b, typeof b) // undefined undefined

    let c = undefined;
    console.log(c, typeof c) // undefined undefined

    console.log(a == b) // true. 값만 비교
    console.log(a === b) // false. 값과 type 비교
    ```

- Number
    ```js
    const a = 1;
    console.log(a, typeof a) // 1 number

    const b = -1.99;
    console.log(b, typeof b) // -1.99 number

    const c = NaN;
    console.log(c, typeof c) // NaN number

    const d = Number('abc')
    console.log(d, typeof d) // NaN number

    const e = Number('37')
    console.log(e, typeof e) // 37 number
    ```

- String

    ```js
    const a = 'cal' + 'som';
    console.log(a, typeof a)

    // Templete String
    const b = `My name is ${a}`
    console.log(b, typeof b)
    ```

- Symbol

    - Symbol은 유일하고 변경 불가능한 (immutable) 기본값 (primitive value).

    ```js
    const c = Symbol('15')
    console.log(c, typeof c) // Symbol(15) symbol

    const d = Symbol('15')
    console.log(d, typeof d) // Symbol(15) symbol

    console.log(c == d) // false
    console.log(c === d) // false

    // new Symbol() - Error: Symbol is not a constructor
    ```

___

**# Falsy & Truethy**

- Falsy 한 값
    ```js
    false, 0, "", null, undefined, NaN  
    ```

- Truthy 한 값
    ```js
    true, 12, 'ABC',{}, []
    ```

```js
if(""){ // false
    console.log('\"\"')
}

if({}){ // true
    console.log('\{\}') // {}
}
```

___

**# `&&` \& `||`**

- 코드 실행 여부
    ```js
    let a = 10
    let b = 20

    a % 5 === 0 && console.log(a) // 10
    a % 6 === 0 && console.log(a) // 실행 안됨
    // 앞 조건이 참일 때만 뒤 코드를 실행

    a % 5 === 0 || console.log(a) // 실행 안됨
    a % 6 === 0 || console.log(a) // 10
    // 앞 조건이 참이면 뒤는 실행 안됨
    ```

- 다양한 비교
    ```js
    alert( alert(1) || 2 || alert(3) ); 
    // alert(1)은 실행은 되지만 undefined을 반환하므로, 가장 처음으로 오는 truthy한 값인 2가 출력됨.
    // OR 연산은 가장 첫 truthy한 값을 출력하고 나머진 무시.

    alert( 1 && null && 2 ); // null
    // AND 연산은 처음으로 오는 falsy한 값을 출력.

    alert( alert(1) && alert(2) );// 1 undefined
    // alert(1)는 falsy한 값인 undefined를 반환하므로 전체를 감싸는 alert는 undefined를 출력.

    alert( null || 2 && 3 || 4 ); // 3
    // &&는 ||보다 우선순위가 높으므로
    alert( null || 3 || 4 );
    // 와 같이 볼 수 있다.
    // 첫번째 truthy한 값인 3이 출력됨.
    ```

___

**# for loop**

- for of
    - iterable한 객체에 사용 (array 등)

- for in
    - 모든 객체에 사용 가능

```js
for(const i of [1, 2, 3]){
    console.log(i)
} // 1, 2, 3

Object.prototype.test = function() {};
// prototype 안에 프로퍼티(test) 설정. 
// 런타임 환경에 따라 오작동 가능성 있음.

for (const i in { a: 1, b: 2, c: 3}) {
    console.log(i)
} // a, b, c, test
```

___
**# Array**

- 2차원 배열 생성
    - 초기값을 할당해 생성
        ```js
        // arr[5][2]
        var arr = [['a','b'], ['c', 'd'], ['e', 'f'], ['g', 'h'], ['i', 'j']];
        ```
    
    - 반복문으로 빈 배열 생성
        ```js
        // arr[5][2]
        var arr = new Array(5);

        for (var i = 0; i < arr.length; i++) {
            arr[i] = new Array(2);
        }
        ```

    - 2차원 배열 생성 함수 만들어서 사용
        ```js
        function create2DArray(rows, columns) {
            var arr = new Array(rows);
            for (var i = 0; i < rows; i++) {
                arr[i] = new Array(columns);
            }
            return arr;
        }

        // arr[5][2]
        var arr = create2DArray(5, 2);
        ```

    - ES6 지원 최신 브라우저에서
        ```js
        // arr[5][2] (빈 배열 생성)
        const arr1 = Array.from(Array(5), () => new Array(2))

        // arr[5][2] (null로 초기화하여 생성)
        const arr2 = Array.from(Array(5), () => Array(2).fill(null))
        ```
___
**# function**

- 익명 함수와 일반 함수 차이
    ```js
    const abc = '123'

    fun() // hoisting으로 초기화 전에 호출 가능

    function fun(efg) {
        console.log(`abc ${abc} ${efg}`) // abc 123 undefined
    } 

    // b(); - ReferenceError: Cannot access 'b' before initialization

    const b = function(efg) {
        console.log(`abc ${abc} ${efg}`)// abc 123 567
    } 

    b('567'); // 익명함수는 hoisting 되지 않음
    ```


- 함수를 객체로 생성
    ```js
    // console.log(plusAll(1, 2, 3)) - ReferenceError: Cannot access 'plusAll' before initialization

    const plusAll = new Function('a', 'b', 'c', 'return a + b + c'); // (인수 1, 2, 3, 함수 바디)

    console.log(plusAll(1, 2, 3)) // 6
    // 익명함수 이므로 hoisting 안됨
    ```

- 익명 함수와 객체 생성 함수의 차이

    ```js
    globalThis.a = 1;

    {
        const a = 100

        const callme = new Function('return a') // 전역 변수 호출

        console.log(callme()) // 1
    }

    {
        const a = 2

        const callme2 = function() { // 지역 변수 호출
            return a
        }

        console.log(callme2()) // 2
    }
    ```

- Arrow Function
    ```js
    const hello = (name, age) => console.log(`hello, I'm ${name}. I'm ${age} years old`)

    hello('Dean', 25) // hello, I'm Dean. I'm 25 years old
    ```

- 생성자 함수를 이용해 새로운 객체를 만들어 내는 방법
    ```js
    function Person(name , age) {
        console.log(this) // Person {}
        this.name = name;
        this.age = age;
        console.log(this) // Person { name: 'Dean', age: 25 }
    }

    const p = new Person('Dean', 25)

    console.log(p) // Person { name: 'Dean', age: 25 }
    console.log(`${p}`) // [object Object]
    console.log(`${p.name}, ${p.age}`) // Dean, 25
    ```

- Arrow Fuction
    ```js
    let func = (arg1, arg2, ...argN) => expression

    let func = (arg1, arg2, ...argN) => {return expression}

    // 위 코드와 동일
    let func = function(arg1, arg2, ...argN) {
    return expression;
    };
    ```
    - 바디가 여러 줄로 구성되어 중괄호로 감싸는 경우, 반환값이 있으면 반드시 return을 입력해주어야한다.

    - Arrow Function은 함수 내부에 this를 생성하지 않음

        ```js
        const Me = (name , age) => {
            console.log(this) 
            this.name = name;
            this.age = age;
            console.log(this) 
        }

        const m = new Me('me', 10) // TypeError: Me is not a constructor
        ```

- 함수 호출시 함수를 생성해 리턴
    ```js
    function plus(num1) {
        return function(num2) {
            return num1 + num2
        }
    }

    const plus5 = plus(5)
    console.log(plus5(10)) // 15
    ```
    
- 함수를 인자로 함수 호출
    ```js
    function fun1(fun, n){
        console.log('hello')
        n++
        fun(n)
    }

    fun1(function(n){
        console.log('funny!', n)
    }, 3)
    // hello
    // funny! 4
    ```

- 프로퍼티에 함수 할당
```js
const obj = {};
obj.a = function () {return 200; }
obj.b = function () {return 300; }
obj.c = function () {return `four hundred`; }

console.log(obj)
console.log(obj.a())
console.log(obj.b())
console.log(obj.c())
/*
{
    a: [Function (anonymous)],
    b: [Function (anonymous)],
    c: [Function (anonymous)]
}
200
300
four hundred
*/

/*
for(const i of obj) {
    console.log(i)
} // TypeError: obj is not iterable
*/

for(const i in obj) {
    console.log(i, typeof i)
} 
/*
a string
b string
c string
*/

console.log(typeof obj, typeof obj.a(), typeof obj.c());
// object number string
```
____

**# Object**

- 객체의 생성과 프로퍼티 설정
    ```js
    var item = 'color'
    var detail = 'black'

    let user = {     // 객체
        name: "John",  // 키: "name",  값: "John"
        age: 30,        // 키: "age", 값: 30
        [`${item}`] : `${detail}`
    };

    user.isAdmin = true
    user['my name is'] = '60!'

    console.log(user)
    ```

- 객체 안 함수
    ```js
    function A(name) {
        this.name = name
        this.hello = function(name) {
            return `hello, ${name}\!`
        }
    }

    const aa = new A('Din', 23)
    
    console.log(aa.name) // Din
    console.log(aa.hello('Joe')) // hello, Joe!
    ```

- 단축 프로퍼티
    ```js
    function makeUser(name, age, color, etc) {
    return {
        name : name,
        age : age,
        color, // 단축 프로퍼티 -> color : color 와 같음
        etc, // , 로 끝나도 됨
    };
    }

    let user = makeUser("John", 30, 'violet', 'unemployed');

    var alert = function (msg) {
        console.log(msg)
    }

    alert(user);
    // { name: 'John', age: 30, color: 'violet', etc: 'unemployed' }

    alert("name" in user) // true

    for (let i in user) {
        alert(`${i} : ${user[i]}`)
    }
    /*
    name : John
    age : 30
    color : violet
    etc : unemployed
    */
    ```

- 메서드 단축 구문
    ```js
    user = {
    sayHi() { // "sayHi: function()"과 동일합니다.
        console.log("Hello");
    }
    };

    user.sayHi()
    ```

- **this**

    - 'this'는 '현재 객체'를 나타낸다
        ```js
        let user = {
        name: "John",
        age: 30,

        sayHi() {
            console.log(this.name);
        }

        };

        user.sayHi(); // John

        // user 객체를 덮어씌움
        user = {
        name: "Mike",
        sayHi() {
        console.log(this.name);
        }}

        user.sayHi(); // Mike
        ```
    - 2
        ```js
        const myObj = function (a, b) { 
        this.a = a;
        this.b = b;
        this.c = function (a, b) {
            return `this.a: ${this.a}, this.b: ${this.b}, a: ${a}, b: ${b}`
        }
        }

        const cc = new myObj(3, 4)

        console.log(cc.c(1,2)) // this.a: 3, this.b: 4, a: 1, b: 2
        ```

___

# **# Methods**

## **Array.sort()**

배열을 오름차순 정렬해준다

- 정렬 규칙 바꾸기
    ```js 
    // sort의 파라미터에 비교함수를 입력

    var a = [1, 4, 3, 8, 2, 5, 9, 7, 6]

    // 내림차순
    console.log(a.sort((a, b) => b - a));
    // [ 9, 8, 7, 6, 5, 4, 3, 2, 1 ]

    // 오름차순
    console.log(a.sort((a, b) => a - b));
    // [ 1, 2, 3, 4, 5, 6, 7, 8, 9 ]

    ```
    함수가 리턴하는 값이 `양수`면 **내림차순**, `음수`면 **오름차순**으로 정렬된다. 0이면 그대로.

##  **Array.from()**

파라미터로 들어오는 객체를 배열로 만들어 준다.

- 일반 사용
    ```js

    console.log(Array.from('foo'));
    // Array ["f", "o", "o"]

    console.log(Array.from(Array(3), (v, i) => i)) 
    // 첫번째 인수 v는 undefined, 두번째 인수 i는 0부터 시작하는 시퀀스 
    // [ 0, 1, 2 ]
    
    console.log(Array.from({ length: 3 }, (_, i) => i)) 
    // {length: 숫자}로 생성할 배열 개수 설정
    // [ 0, 1, 2 ]

    console.log(Array.from([1, 2, 3], x => x + x)); // [ 2, 4, 6 ]

    console.log(Array.from(Array(5).fill(5))); // [ 5, 5, 5, 5, 5 ]

    console.log(Array.from(Array(3).fill([3,4,5]))); 
    // [ [ 3, 4, 5 ], [ 3, 4, 5 ], [ 3, 4, 5 ] ]
    
    console.log(Array.from({length: 5}, (_, i) => Array(i).fill(i))); 
    // [ [ 1 ], [ 2, 2 ], [ 3, 3, 3 ] ]

    console.log(Array.from(Array(3), () => [1,2,3])) // 각 배열에 배열[1,2,3]을 삽입
    // [ [ 1, 2, 3 ], [ 1, 2, 3 ], [ 1, 2, 3 ] ]

    console.log(Array.from(Array(5), (_, i) => [i, i+1, i+2]))
    // [ [ 0, 1, 2 ], [ 1, 2, 3 ], [ 2, 3, 4 ], [ 3, 4, 5 ], [ 4, 5, 6 ] ]

    ```

- range() 구현
    ```js
    // Sequence generator function (commonly referred to as "range", e.g. Clojure, PHP etc)
    const range = (start, stop, step) => Array.from({ length: (stop - start) / step + 1}, (_, i) => start + (i * step));

    // Generate numbers range 0..4
    console.log(range(0, 4, 1))
    // [0, 1, 2, 3, 4]

    // Generate numbers range 1..10 with step of 2
    console.log(range(1, 10, 2))
    // [1, 3, 5, 7, 9]
    ```

___

## **Null 병합 연산자**

- null이나 undefined가 아닌 첫 번째 피연산자를 반환한다.
    ```js
    console.log(a ?? b); // 아래 코드와 동일한 동작

    console.log((a !== null && a !== undefined) ? a : b)

    let firstName = null;
    let lastName = null;
    let nickName = "바이올렛";

    alert(firstName ?? lastName ?? nickName ?? "익명의 사용자"); // 바이올렛
    ```

- `??`와 `||`의 차이

    `||`는 첫 번째 truthy 값을 반환한다.  
    `??`는 첫 번째 정의된(defined) 값을 반환한다.

    ```js
    let height = 0;

    alert(height || 100); // 100
    alert(height ?? 100); // 0
    ```
    `||`는 height를 falsy한 값으로 취급해서 null이나 undefined와 동일하게 처리한다.  
    `??`는 height가 null이나 undefined일때만 100이 된다.  
    높이처럼 0을 할당할 수 있는 변수를 사용할 때엔 ||보다 ??가 좋다.

- 연산자 우선순위

    `??`의 연산자 우선순위는 5이므로 대부분의 연산자보다 나중에 평가된다.
    ```js
    let height = null;
    let width = null;

    // 괄호를 추가!
    let area = (height ?? 100) * (width ?? 50);

    alert(area); // 5000
    ```
    에서 괄호가 없으면 의도대로 연산되지 않는다.

- 제약사항

    안전성 관련 이슈로 `??`는 `&&`나 `||`와 함께 사용하지 못한다
    ```js
    let x = 1 && 2 ?? 3; // SyntaxError: Unexpected token '??'

    let x = (1 && 2) ?? 3; // 괄호를 사용하면 제대로 동작한다.
    ```

- null이 아닌 값 할당
    ```js
    // height가 null이나 undefined인 경우, 100을 할당
    height = height ?? 100;
    ```

___

## **Strict mod**

- 엄격 모드
    ```js
    // 스크립트 최상단
    'use strict'
    ``` 
모던 자바스크립트에서 지원하는 모든 기능을 활성화한다.


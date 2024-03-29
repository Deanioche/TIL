**# JS 메모**

## **node.js에서 입력 받는 방법 두가지**

### **1. readline 모듈 사용**

- 소스 코드1 (한 줄 입력)
    ```js
    const readline = require('readline');

    const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
    });

    rl.on('line', function(line) {
    console.log(line);

    rl.close();
    }).on("close", function() {
    process.exit();
    });
    ```

- 소스 코드2 (여러 줄 입력)
    ```js
    const readline = require('readline');

    const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
    });

    let input = [];

    rl.on('line', function (line) {
    input.push(line)
    })
    .on('close', function () {
    console.log(input);
    process.exit();
    });
    ```

### **2. fs 모듈 사용**
- 소스 코드1 (한 줄 입력)
    ```js
    let fs = require('fs');
    let input = fs.readFileSync('/dev/stdin').toString().split(' ');

    let num = Number(input);

    for (let i = 1; i <= num; i++) {
    console.log(i);
    }
    ```

- 소스 코드2 (여러 줄 입력)
    ```js
    let fs = require('fs');
    let input = fs.readFileSync('/dev/stdin').toString().split('\n');

    let count = input[0];
    let numbers = [];

    for (let i = 1; i < input.length; i++) {
    if (input[i] !== '') {
        numbers.push(input[i].split(' '));
    }
    }

    for (let i = 0; i < numbers.length; i++){
    let num1 = Number(numbers[i][0]);
    let num2 = Number(numbers[i][1]);

    console.log(num1 + num2);
    }
    ```
___

## **number타입 범위와 BigInt()**

- number타입은 -(2⁵³-1) 부터 2⁵³ -1 까지는 정확히 IEEE-754로 표현될 수 있지만, 그 초과와 이하 는 IEEE-754로 직접 표현될 수 없으며 가까운 수나 0으로 반올림 한다.

- number의 범위를 넘는 정수는 BigInt()로 나타낼 수 있다.

[Bigint_doc](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/BigInt)

```js
i = 9223372036854775807
j = 9223372036854775808
console.log((BigInt(i) + BigInt(j)).toString()) // 18446744073709551615
```

___

## **문자열 뒤집기 reverse()**

- reverse()는 원본 배열을 변형시키므로 원하지 않으면 배열을 복사해서 써야한다.

```js
let a = 'ABC'

console.log([...a].reverse().join('')) // CBA
console.log(a.split('').reverse().join('')) // CBA
console.log(a) // ABC 원본은 안바뀜
```
- 재귀함수 이용
    ```js
    function reverse (str) {
        if (str === "") {
            return "";
        } else {
            return reverse(str.substr(1)) + str.charAt(0);
        }
    }
    ```

___

## **아스키 코드 변환**

```js
console.log("A".charCodeAt())           // 65
console.log(String.fromCharCode(65))    // A
console.log("BCD".charCodeAt())         // 66 맨 앞자리만 출력
console.log(String.fromCharCode(65, 66, 67, 68, 69))    // ABCDE
```
___

## **문자 반복(Array.join(), repeat())**

```js
console.log(Array(6).join('A'))          // AAAAA
console.log(Array(5).fill('A').join('')) // AAAAA

// ES6
console.log('A'.repeat(5)) // AAAAA
```

___

## **console.log 대신 개행 없이 출력**

```js
process.stderr.write("1");
process.stderr.write("2");
// 12
```

___

## **0부터 n까지 정수 배열 생성**

```js
console.log([...Array(5)].map((v, i) => i))         // [0, 1, 2, 3, 4]
console.log(Array.from({ length: 5 }, (v, i) => i)) // [0, 1, 2, 3, 4]

// Set
console.log(new Set([...Array(5)].map((v, i) => i))) // Set(5) { 0, 1, 2, 3, 4 }

// key : value
console.log({ ...[...Array(5)].map((v, i) => i) })   // { '0': 0, '1': 1, '2': 2, '3': 3, '4': 4 }
```

___

## **# str -> int**

```js
let n = '3';
console.log(typeof +n) // number
console.log(+n) // 3
```

___

## **# NaN 비교 isNaN()**

```js
let t = 'A';

console.log(typeof t);   // string
console.log(typeof +t);  // number
console.log(+t);         // NaN   
console.log(+t === NaN); // false 
console.log(isNaN(+t));  // true
```

___

## **# 소수점 자리수 지정**

```js
console.log(21.47483648.toFixed(0)) // 21
console.log(21.47483648.toFixed(3)) // 21.475
console.log(21.47483648.toFixed(5)) // 21.47484
```

___

## **# 배열안의 원소 값 모두 합치기**

```js
let a = [1, 2, 3];

console.log(a.reduce((a, b) => a + b)); // 6
```

___

## **# 배열에서 중복 제거하는 방법 set**

[JS 배열 중복 제거](https://velog.io/@yunsungyang-omc/JS-%EB%B0%B0%EC%97%B4%EC%97%90%EC%84%9C-%EC%A4%91%EB%B3%B5-%EC%A0%9C%EA%B1%B0%ED%95%98%EA%B8%B0)

```js
const array = ['a' , 1, 2, 'a' , 'a', 3];

// 1: 'Set'
[...new Set(array)];
// 2: 'Filter'
array.filter((item, index) => array.indexOf(item) === index);
// 3: 'Reduce'
array.reduce((unique, item) =>
  unique.includes(item) ? unique : [...unique, item], []);
// RESULT:
// ['a', 1, 2, 3]
```

**# 성능 비교**
![image](https://user-images.githubusercontent.com/66513003/138716223-c299eafe-76a7-4ee2-9a58-2c974de5973d.png)
___

# **# Methods**

## **Array**
- reverse()
    ```js
    array.reverse()
    ```
    배열 순서가 뒤집힘 [1, 2, 3] -> [3, 2, 1]

## **String**
- padStart/padEnd

    ```js
    // 자릿수 맞추기
    console.log("1".padStart(3, "0")) // 001
    console.log("1".padEnd(4, "0")) // 1000
    ```
    설정한 자리수만큼 0을 채워줌

___

# **# Objects**

## **Date()**

- Date 출력 설정

    ```js
        var date = new Date();

        var options = {
            year: "numeric",
            month: "2-digit",
            day: "numeric",
            hour: 'numeric',
            minute: 'numeric',
            second: 'numeric',
            timezone: 'short'
        };

    console.log(
        date.toLocaleDateString("en", options) //en is language option, you may specify..
    );
    ```
- Options

    ```js
    Option          Values          Sample output
    ----------------------------------------------------
    weekday         'narrow'        'M'
                    'short'         'Mon'
                    'long'          'Monday'

    year            '2-digit'       '01'
                    'numeric'       '2001'

    month           '2-digit'       '01'
                    'numeric'       '1'
                    'narrow'        'J'
                    'short'         'Jan'
                    'long'          'January'

    day             '2-digit'       '01'
                    'numeric'       '1'

    hour            '2-digit'       '12 AM'
                    'numeric'       '12 AM'

    minute          '2-digit'       '0'
                    'numeric'       '0'

    second          '2-digit'       '0'
                    'numeric'       '0'

    timeZoneName    'short'         '1/1/2001 GMT+00:00'
                    'long'          '1/1/2001 GMT+00:00'
    ```

- 한국시간 출력

    ```js
    var date = new Date();

    var options = {
        weekday: "short",
        year: "numeric",
        month: "2-digit",
        day: "numeric",
        hour: "numeric",
        minute: "numeric",
        second: "numeric"
    };

    // Korean uses 12-hour time with AM/PM
    console.log(date.toLocaleTimeString('ko-KR', options));
    ```
___

### **Web Storages**
- 세션 스토리지
    - 세션 스토리지(SessionStorage)는 탭 안에서만 유효하며 탭이 닫히면 스토리지도 종료된다.
    - 저장공간 약 5MB
    - 동기(Synchronous)방식이기 때문에 메인 스레드의 동작을 막을 수 있다.
    - 탭 안에서만 유효하기 때문에 웹 워커나 서비스 워커가 접근할 수 없다.
    - string 타입만 저장이 가능

- 로컬 스토리지
    - 약 5MB의 저장공간
    - 동기(Synchronous)방식이며 메인 스레드의 연산을 중단시키기 때문에 사용이 지양됨.
    - string 타입만 저장이 가능


### **setInterval 에서 함수 호출**

자바스크립트의 function은 객체이다.  
만약 fun 이라는 이름의 funtion이 있다면  
`fun`은 함수를 호출하는 **객체**이고 `fun()`은 함수를 실행시키는 코드이다.
```js
setInterval(fun(), 1000)
```
위 코드는 1초마다 fun 함수를 호출하는게 아닌, fun()함수가 실행되고 그 결과로 리턴되는 데이터를 매 초 동작시키는게 된다.  
만약 fun 함수의 리턴값이 true라면,  
1초마다 true를 반복하는 코드, 즉 아무런 의미가 없는 코드이다.  

원래 의도대로 매 초마다 fun() 함수가 동작하도록 하려면
```js
setInterval(fun, 1000)
```
이렇게 작성해야 한다.


___

**# style.css에 입력된 특정 object의 css속성을 JS에서 호출하기**

```html
<body>
    <div class=".object"></div>
</body>
```

```css
.object {
    background : lightgrey;
    display : relative;
}
```

```js
var object =  document.querySelector('.object');
var object_style = window.getComputedStyle(object, null);

console.log(object_style.background); // lightgrey
// object의 css - background 정보를 출력. 
console.log(object_style.display); // relative
// object의 css - display 정보를 출력. 
```

# 함수

**# Template Literal**
- From ES6
- use Backtick ``

```js
var name = 'World';

console.log(`Hello, ${name}!`); // Hello, World!
```

**# Arrow Function**

- 1
```js
var name = 'World';

const hello = (name) => {
    console.log(`Hello, ${name}!`) ;
}

hello(name); // Hello, World!
```

- 2
```js
var name = 'World'

const hello = (name) => `Hello, ${name}!` 

console.log(hello(name)); // Hello, World!
```
- 3
```js
// Traditional Function
function bob (a){
    return a + 100;
}
  
// Arrow Function
let bob = a => a + 100;  
```

- map
```js
const materials = [
  'Hydrogen',
  'Helium',
  'Lithium',
  'Beryllium'
];

console.log(materials.map(material => material.length));
// Array [8, 6, 7, 9]
```

___

# 객체

**# 비구조 할당 (객체 구조 분해)**

- 비구조 할당
```js
const me = {
    name : 'Fin',
    job : 'unemployed',
    age : 25
}
const {name, job, age} = me;
console.log(`${name}, ${job}, ${age}`); // Fin, unemployed, 25
```

- 파라미터에 비구조 할당
```js

// create the object 'me' as above

const info = ({name, job, age}) => {
    console.log(`${name}, ${job}, ${age}`);
}

info(me); // Fin, unemployed, 25
```

**# this**

- 1
```js
const me = {
    name : 'Fin',
    job : 'unemployed',
    age : 15,
    say : function say() { // input function into object
        console.log(`I'm ${this.job}!`)
    },
    why(){ // short
        console.log(`I'm only ${this.age} years old!`)
    },
} 

me.say() // I'm unemployed!
me.why() // I'm only 15 years old!

const you = {
    name : 'Din',
    job : 'employed',
    age : 35
}

you.say = me.say // copy the function 'say()'
you.say() // I'm employed!
```
- 2
```js
const me = {
    name : 'Fin',
    job : 'unemployed',
    age : 15,
    say : function say() { // input function into object
        console.log(`I'm ${this.job}!`)
    },
    why(){ // short
        console.log(`I'm only ${this.age} years old!`)
    },
    get info() {
        console.log('get info() 동작')
        return [this.name, this.job, this.age]
    },

    set setName(name) { // cannot be existed name
        console.log('setName() 동작')
        this.name = name
    }
} 

console.log(me.info) // [ 'Fin', 'unemployed', 15 ]
me.setName = 'Hoo'

console.log(me.info) // [ 'Hoo', 'unemployed', 15 ]
```

___

# foreach

- ex 1
```js
const names = ['James', 'Anna', `Berlin`, `Mina`];

function print(names){
    console.log(names);
}

names.forEach(print); // array 'names'

names.forEach((names, index, array, c, d) => {
    console.log(index, names, array);
}); // array 'names'
```
- ex 2
```js
// Arrow function
forEach((element) => { ... } )
forEach((element, index) => { ... } )
forEach((element, index, array) => { ... } )

// Callback function
forEach(callbackFn)
forEach(callbackFn, thisArg)

// Inline callback function
forEach(function callbackFn(element) { ... })
forEach(function callbackFn(element, index) { ... })
forEach(function callbackFn(element, index, array){ ... })
forEach(function callbackFn(element, index, array) { ... }, thisArg)
```

- ex 3
```js
let ratings = [5, 4, 5];
let sum = 0;

let sumFunction = async function (a, b)
{
  return a + b
}

ratings.forEach(async function(rating) {
  sum = await sumFunction(sum, rating)
})

console.log(sum)
// Naively expected output: 14
// Actual output: 0
```
___

## **기존방식과 ES6 ECMA script 방식 차이**
```js
// 기존 방식
const movies = await axios.get("https://yts-proxy.now.sh/list_movies.json")
console.log(movies.data.data.movies)

// ES6 ECMA script 방식
const { data: { data: { movies } } } = await axios.get("https://yts-proxy.now.sh/list_movies.json")
console.log(movies)  // 받은 데이터(객체) 내부의 필요한 데이터만 저장할 수 있다
```

___

## **함수 파라미터에서 인수 기본값 삽입**

```js
function abc(a = 7){
    return a
}

console.log(abc(8)) // 8
console.log(abc()) // 7
```

함수 abc의 인수 a에 **들어오는 값이 없으면** 7로 초기화된다.

___

## **함수 실행에 쿨타임 주기**

```js
const throttle = (func, delay) => {
    let prev = Date.now() - delay;

    return (...args) => {
        let current = Date.now();
        if (current - prev >= delay) {
            console.log(args)
            prev = current;
            func.apply(null, args);
        }
    }
};

const fun () => {
    console.log("mouse location:", e.clientX, e.clientY);
}

// 마우스가 움직이면 2초마다 함수 fun이 동작
document.addEventListener('mousemove', throttle(fun, 2000));
```

___

## 나머지 매개변수 

[ko.javascript.info/rest-parameters-spread](https://ko.javascript.info/rest-parameters-spread)

(...arg)


```js
function showName(firstName, lastName, ...titles) {
  alert( firstName + ' ' + lastName ); // Julius Caesar

  // 나머지 인수들은 배열 titles의 요소가 됩니다.
  // titles = ["Consul", "Imperator"]
  alert( titles[0] ); // Consul
  alert( titles[1] ); // Imperator
  alert( titles.length ); // 2
}

showName("Julius", "Caesar", "Consul", "Imperator");
```

## 전개 문법(spread syntax)

함수를 호출할 때 `...arr`를 사용하면, **이터러블 객체 arr**이 인수 목록으로 '확장’됩니다.

- 혼합 사용이 가능

    ```js
    let arr1 = [1, -2, 3, 4];
    let arr2 = [8, 3, -8, 1];

    alert( Math.max(1, ...arr1, 2, ...arr2, 25) ); // 25
    ```

- 배열 선언에도 사용 가능

    ```js
    let arr = [3, 5, 1];
    let arr2 = [8, 9, 15];

    let merged = [0, ...arr, 2, ...arr2];

    alert(merged); // 0,3,5,1,2,8,9,15 (0, arr, 2, arr2 순서로 합쳐집니다.)
    ```

- 문자열의 배열화
    
    ```js
    let str = "Hello";

    alert( [...str] ); // H,e,l,l,o

    // Array.from은 이터러블을 배열로 바꿔줍니다.
    alert( Array.from(str) ); // H,e,l,l,o
    ```

___

## **apply**

[call, apply, bind 설명](https://www.zerocho.com/category/JavaScript/post/57433645a48729787807c3fd)

apply(this, args) 

첫번째 인수 this에는 해당 함수에서의 this를 대체할 다른 this을 꽂아줄 수 있다.  
    -> 다른 객체의 함수를 자기꺼마냥 쓸 수 있음.

두번째 인수 arg는 전달할 **유사 배열** 객체

```js
var obj = {
  string: 'zero',
  yell: function() {
    alert(this.string);
  }
};
var obj2 = {
  string: 'what?'
};
obj.yell(); // 'zero';
obj.yell.call(obj2); // 'what?'
```

## **유사 배열**

console.log로 찍어보면 배열처럼 나오지만 배열 함수를 사용할 수 없다.

```js
function example() {
  console.log(arguments);
}
example(1, 'string', true); // [1, 'string', true]
```

___

## 배열을 ','없이 문자열로 만드는 법

```js
const arr = [0, 1, 2, 3, 4, 5];

// arr.toString() => "0,1,2,3,4,5" 가 된다.

arr.join("") // "012345"가 된다.

console.log([...Array(9).fill(0), 5].join(""));
// 0000000005
```

___

## 색상코드 - 255 -> 16진법으로

https://stackoverflow.com/questions/5623838/rgb-to-hex-and-hex-to-rgb

```js
function componentToHex(c) {
  var hex = c.toString(16);
  return hex.length == 1 ? "0" + hex : hex;
}

function rgbToHex(r, g, b) {
  return "#" + componentToHex(r) + componentToHex(g) + componentToHex(b);
}

alert(rgbToHex(0, 51, 255)); // #0033ff
```

___


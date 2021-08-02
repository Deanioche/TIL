**# JS 메모**

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

**#**

___

- 기존방식과 ES6 ECMA script 방식 차이
    ```js
    // 기존 방식
    const movies = await axios.get("https://yts-proxy.now.sh/list_movies.json")
    console.log(movies.data.data.movies)

    // ES6 ECMA script 방식
    const { data: { data: { movies } } } = await axios.get("https://yts-proxy.now.sh/list_movies.json")
    console.log(movies)  // 받은 데이터(객체) 내부의 필요한 데이터만 저장할 수 있다
    ```
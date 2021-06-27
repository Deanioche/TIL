**# JS 메모**

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
___





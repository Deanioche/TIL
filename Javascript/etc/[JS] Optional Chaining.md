# **[JS] Optional Chaining**

## **(?.)**

ref : https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Operators/Optional_chaining

component의 로딩이 완료되기 전, component의 요소를 사용하는 함수를 실행하면 에러 또는 undefined가 뜨게 된다.

이 때, 사용하려는 객체 뒤에 "?."를 붙여주면 해당 객체가 **null 또는 undefined**가 아닐 때 함수가 실행된다.
```js
myInput.current.focus()
// 실행시 Cannot read property 'focus' of undefined가 뜬다.

myInput.current?.focus()
```
myInput.current 가 null 또는 undefined가 아니면
focus()를 실행
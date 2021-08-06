## **에러**

```
index.js:1 Warning: Each child in a list should have a unique "key" prop.

Check the render method of `App`. See https://reactjs.org/link/warning-keys for more information.
    at Potato (http://localhost:3000/static/js/main.chunk.js:25:3)
    at App
```

React의 모든 Component는 고유한 id를 가져야 한다.

```js
var arr = ['Sushi', 'potato', 'Compost', 'Burger'];

function renderFood(dish) {
  return <Potato key={arr.indexOf(dish)} name={dish} />
}
```
jsx에서 호출하려는 function의 key={}에 해당 컴포넌트만이 가지는 고유값을 담아주어야 한다.

___
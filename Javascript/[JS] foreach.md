**# foreach**

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
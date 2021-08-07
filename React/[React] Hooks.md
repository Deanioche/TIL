# **React Hooks**

react hook은 funtional component에서 state를 가질 수 있게 해준다.
앱을 리액트 Hook으로 만들면, class component, did mount, render 이런 것들을 쓰지 않아도 되어, 모든 것은 하나의 function이 된다. => functional programming [함수형 프로그래밍]


### **기존**
```js
    import React from 'react';

    class App extends React.Component {
        state = {
            count: 0
        };

        modify = n => {
            this.setState({
                count : n
            });
        };

        render() { 
            return (
                <>
                <h1>{count}</h1>
                <button onClick={() => this.modify(count + 1)}>Increment</button>
                </>
            );
        }
    }

    export default App;
```

### **React Hook**

```js
    import React, { Component, useState } from 'react';
    // Component, useState를 임포트

    const App = () => {
        const [count, setCount] = useState(0);
        // useState는 두가지를 사용할 수 있게 한다.
        // 하나는 value
        // 하나는 value를 변경하는 방법.

        // useState는 array를 리턴하는데, 
        // 첫번째 요소 = value
        // 두번째 요소 = setter이다.

        // useState의 파라미터에는 value의 초기화 값을 담아준다.

        return (
            <>
                {count}
                <button onClick={() => setCount(count + 1)}>Increment</button>
            </>
        )
    }
```


## **useTitle**
## **useInput**
## **usePageLeave**
## **useClick**
## **useFadeIn**
## **useFullscreen**
## **useHover**
## **useNetwork**
## **useScroll**
## **useTabs**
## **usePreventLeave**
## **useConfirm**
## **useAxios**
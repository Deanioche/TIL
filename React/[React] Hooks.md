# **React Hooks**

react hook은 functional component에서 state를 가질 수 있게 해준다.
앱을 리액트 Hook으로 만들면, class component, did mount, render 이런 것들을 쓰지 않아도 되어, 모든 것은 하나의 function이 된다. => functional programming [함수형 프로그래밍]

# **Hook 사용 규칙**
Hook은 그냥 JavaScript 함수이지만, 두 가지 규칙을 준수해야 합니다.

최상위(at the top level)에서만 Hook을 호출해야 합니다. 반복문, 조건문, 중첩된 함수 내에서 Hook을 실행하지 마세요.

React 함수 컴포넌트 내에서만 Hook을 호출해야 합니다. 일반 JavaScript 함수에서는 Hook을 호출해서는 안 됩니다. (Hook을 호출할 수 있는 곳이 딱 한 군데 더 있습니다. 바로 직접 작성한 custom Hook 내입니다. 이것에 대해서는 나중에 알아보겠습니다.)

함수 이름은 "use"로 시작되어야한다.


### **기존 State 사용법**
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

### **React Hook useState**

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

___

## **useInput**
     
    input 이벤트를 완전히 다른 function로 처리할 수 있게 할 수 있다.
    이벤트와 분리된 파일, 다른 entity에 연결해서 처리할 수 있다.

- App.js
    ```js
    import React, { useState } from "react";

    const useInput = (initVal) => {
        const [value, setVal] = useState(initVal);
        const onChange = (e) => {
            console.log(e.target);
        };
    // 값이 변경될 때 마다 event의 target 출력
    // target == <input value="surimi"></input>

        return { value, onChange }; 

    // value나 onChange 같은 메소드 이름은 바꿀 수 없다.
    };

    const App = () => {
        const myName = useInput("surimi");

        return (
            <div className="App">
                <h1>Hello CodeSandbox</h1>
                <h2>Start editing to see some magic happen!</h2>
                <input {...myName} />
            </div>
        );
    };

    export default App;
    ```

    {...myName} 는 spread operator(스프레드 연산자)  
    value={myName.val} onChange={myName.onChange}'와 같음

    - spread operator(스프레드 연산자)란?  
    https://www.techiediaries.com/react-spread-operator-props-setstate/

    input의 값을 변경하려 하면  
    Warning: You provided a `value` prop to a form field without an `onChange` handler. This will render a read-only field. If the field should be mutable use `defaultValue`. Otherwise, set either `onChange` or `readOnly`.  
    이런 에러가 뜨는데 왜???  


## input 입력 길이를 제한하는 Hook

```js
import React, { useState } from "react";
import styled from "styled-components";

const useInput = (initVal, validator) => { 
    // validator는 유효성 검사 조건이 입력되어있는 function을 받음. 
  const [value, setValue] = useState(initVal);
  const onChange = event => {
    const {
      target: { value }
    } = event; // ES6
    // ES6 이전 동일한 기능 => const value = event.target.value;

    let willUpdate = true;
    if (typeof validator === "function") {
      willUpdate = validator(value);
    }

    if (willUpdate) {
      setValue(value);
    }
  };

  return { value, onChange };
};


const App = () => {
  const maxLen = value => value.length < 10; // input 입력 길이 제한
  const myName = useInput("surimi", maxLen);

  return (
    <div className="App">
      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>
      <input {...myName} />
    </div>
  );
};

export default App;
```


___

## **useTitle**

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
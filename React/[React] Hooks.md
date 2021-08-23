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

## **useTabs**

데이터 배열 길이에 따라 탭이 생성되고 전환할 수 있는 Hook

API
```js
const content = [
  {
    tab: "Section 1",
    content: "I'm the content of the Section 1"
  },
  {
    tab: "Section 2",
    content: "I'm the content of the Section 2"
  }
  ,
  {
    tab: "Section 3",
    content: "I'm the content of the Section 3"
  }
];
```

useTab.js
```js
import { useState } from 'react'

export const useTabs = (initialTab, allTabs) => {
    const [currentIndex, setCurrentIndex] = useState(initialTab);
    if (!allTabs || !Array.isArray(allTabs)) {
        // allTabs가 undefined이거나 배열이 아니면 return
        return;
    }
    return {
        currentItem: allTabs[currentIndex],
        changeItem: setCurrentIndex // setter 함수 반환
    };
};
```

App.js
```js
const App = () => {
  const inputCondition = value => value.length <= 10 && !value.includes("@");
  const myName = useInput("surimi", inputCondition);

  const { currentItem, changeItem } = useTabs(0, content);

  return (
    <div className="App">
      <h1>Hello React Hook</h1>

      <p>useInput</p>
      <input {...myName} />

      <p>useTabs</p>
      {content.map((section, index) => (
        <button onClick={() => changeItem(index)}>{section.tab}</button>
      ))}
      <p>{currentItem.content}</p>

    </div>
  );
};
```





___






## **useEffect**

useEffect는 ComponentDidMount와 ComponentWillUpdate, ComponentWillUnMount의 역할을 한다.

- **ComponentDidMount**되거나 **ComponentWillUpdate**되면 sayHello() 함수 실행
	```js
	import { useEffect } from "react";

	const App = () => {

	const [num1, setNum1] = useState(0);
	const [num2, setNum2] = useState(0);
	const sayHello = () => console.log("hello, useEffect!")

	useEffect(() => {
		sayHello();
	})

	return (
        <div className="App">
            <button onClick={() => setNum1(num1 + 1)}>{num1}</button>
            <button onClick={() => setNum2(num2 + 1)}>{num2}</button>
        </div>
	)
	}
	```
	초기화시, 새로고침시, 어느 버튼을 누를 시에도 sayHello가 실행된다.

- useEffect의 파라미터
    1. useEffect의 첫번째 argument로는 익명함수를 생성할 필요 없이 실행하고자 하는 함수를 바로 넣을 수 있다.
    2. 두번째 argument에는 useEffect가 반응할 state의 **배열**을 넣을 수 있다. 이 배열을 argument로 삽입할 경우, 배열에 들어있지 않은 state에는 useEffect가 동작하지 않는다. 어떤 state에도 동작하지 않게 하려면 빈 배열 '[]'을 삽입하면 된다.
    3. useEffect로부터 return되는 함수는 ComponentWillUnMount로서 동작한다.

	```js
	import { useEffect } from "react";

	const App = () => {

        const [num1, setNum1] = useState(0);
        const [num2, setNum2] = useState(0);
        const sayHello = () => console.log("hello, useEffect!")

        useEffect(sayHello, [num1]);
        // 배열안에 있는 state에 의해서만 useEffect가 동작한다.

        return (
            <div className="App">
                <button onClick={() => setNum1(num1 + 1)}>{num1}</button>
                <button onClick={() => setNum2(num2 + 1)}>{num2}</button>
            </div>
        )
	}
	```
    초기화, 새로고침, num1이 업데이트 될 때만 useEffect가 실행된다.


    




___





## **useTitle**

input 입력으로 실시간 HTML title 변경하기

```js
const App = () => {

    // useEffect
    const useTitle = initTitle => {
        const [title, setTitle] = useState(initTitle);
        const updateTitle = () => {
            const htmlTitle = document.querySelector("title");
            htmlTitle.innerText = title;
        }
        useEffect(updateTitle, [title]);
        return setTitle
    }

    const titleUpdater = useTitle("Loading...");

    return (
        <div className="App">
            <p>useEffect</p>
            <input onChange={(p) => titleUpdater(p.target.value)} placeholder="change title" />
        </div>
    );
};
```



___

## **useRef**

Component의 어떤 부분을 선택하는 방법
getElementById 처럼 HTML에 접근할 수 있게 됨.

```js
import { useRef } from "react";

const App = () => {

    // useRef
    const myInput = useRef();
    setTimeout(() => myInput.current?.focus(), 3000);

    // [Optional chaining]
    // myInput.current?.focus()
    // myInput.current 가 null 또는 undefined가 아니면
    // focus()를 실행

    return (
        <div className="App">
            <h3># useRef</h3>
            <input ref={myInput} placeholder="useRef"></input>
        </div>
    );
};
```




___



## **useClick**

Component의 mount, unmount에 따라 useRef로 참조하는 HTMl 태그의 이벤트리스너 추가/ 제거.

```js
import { useEffect, useRef } from "react";

// useClick
const useClick = (fun) => {
    const element = useRef();
    useEffect(() => {
        if (typeof fun !== "function") {
            return;
        }
        // Component 가 mount 되었을 때,
        if (element.current) {
            element.current.addEventListener('click', fun)
        }
        // Component 가 unmount 되었을 때,
        return () => {
            // componentWillUnmount때 작동할 함수
            if (element.current) {
                element.current.removeEventListener("click", fun)
            }
        }
    }, []); // dependency는 없음 = componentUpdate에는 반응하지 않음
    return element;
}

const App = () => {

    // useClick
    const sayHello = () => console.log("say Hello");
    const title = useClick(sayHello);

    return (
        <div className="App">

            <h3># useClick</h3>
            <h2 ref={title}>click me!</h2>

            <hr />
        </div>
    );
};
```



___

## **useConfirm**

useState와 useEffect를 사용하지 않기 때문에 Hook이 아니다

사용자가 무언가 하기 전에 확인하는 기능

**useConfirm.js**
```js
export const useConfirm = (msg, onConfirm, onCancel) => {
    if (typeof onConfirm !== "function") return;

    const confirmAction = () => {
        if (window.confirm(msg)) onConfirm();
        else
            try { onCancel(); } // onCancel이 없는 경우
            catch (err) { console.log("abort function doesn't exiest!"); return };
    }

    return confirmAction;
}
```

**App.js**
```js

// Hooks 
import { useConfirm } from "./modules/exports"

const App = () => {

    // useConfirm
    const deleteConsole = () => console.clear();
    const abort = () => console.log("Console clear aborted.");
    const confirmDel = useConfirm("Are you sure?", deleteConsole, abort);

    return (
        <div className="App">
            <h3># useConfirm</h3>
            <button onClick={confirmDel}>delConsole</button>

            <hr />
        </div>
    );
};
```


___


## **usePreventLeave**
useState와 useEffect를 사용하지 않기 때문에 Hook이 아니다

중요한 작업 중 실수로 페이지가 꺼지거나 이동되지 않게 방지하는 기능

usePreventLeave.js
```js
export const usePreventLeave = () => {
    const listener = event => {
        event.preventDefault();
        event.returnValue = "";
    }
    const enablePrevent = () => window.addEventListener("beforeunload", listener);
    const disablePrevent = () => window.removeEventListener("beforeunload", listener);
    return { enablePrevent, disablePrevent }
}

// return { enablePrevent, disablePrevent }는
// return { enablePrevent : enablePrevent, disablePrevent : disablePrevent }와 같음
```

**App.js**
```js
import { usePreventLeave } from "./modules/exports"

const App = () => {

    // usePreventLeave
    const { enablePrevent, disablePrevent } = usePreventLeave();

    return (
        <div className="App">
            <h3># usePreventLeave</h3>
            <button onClick={enablePrevent}>Protect</button>
            <button onClick={disablePrevent}>UnProtect</button>
            <br />
            <span>Enable 'Protect' and refresh the window!</span>

            <hr />
        </div>
    );
};
```

___

## **useBeforeLeave**

**useBeforeLeave.js**
```js
export const useBeforeLeave = onBefore => {

        useEffect(() => {
            document.addEventListener("mouseleave", handle);
            return () => document.removeEventListener("mouseleave", handle);
        }, []);

        if (typeof onBefore !== "function") {
            return;
        }
        const handle = (event) => {
            const { clientY } = event;
            if(clientY <= 0) onBefore();
        }
        
    }
```


___



## **usePageLeave**

## **useFadeIn**
## **useFullscreen**
## **useHover**
## **useNetwork**
## **useScroll**
## **useAxios**
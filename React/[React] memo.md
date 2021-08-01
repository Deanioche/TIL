## **React memo**

___


## **설치**
```
npx install create-react-app [설치할 폴더]
```
이 명령어만으로 Webpack, Babel 등을 설치 할 필요 없이 한번에 리액트 개발 세팅을 해줌

___

## **리액트 동작**

- index.html
    ```html
        ...
    <body>
        <noscript>You need to enable JavaScript to run this app.</noscript>
        <div id="root"></div>
        <!--
        This HTML file is a template.
        If you open it directly in the browser, you will see an empty page.

        You can add webfonts, meta tags, or analytics to this file.
        The build step will place the bundled scripts into the <body> tag.

        To begin the development, run `npm start` or `yarn start`.
        To create a production bundle, use `npm run build` or `yarn build`.
        -->
    </body>
    </html>
    ```

    리액트는 실행시, 작성한 모든 react application (html css js)을 <div id="root"></div> 안에서 동작시킨다.

- index.js
    ```js
    import React from 'react';
    import ReactDOM from 'react-dom';
    import App from './App';

    ReactDOM.render(
    <React.StrictMode>
        <App />
    </React.StrictMode>,
    document.getElementById('root')
    );
    ```
    index.js를 보면, App.js를 import해서 id가 'root'인 태그 안에 App.js의 내용을 삽입한다.

___

## **Component**

Component는 HTML을 반환하는 함수.
**JSX는 JS안의 HTML**

- App.js의 Component
    ```js
    function App() {
    return (
        <div>Heloo!!!!</div>
    );
    }
    ```

- index.js에서의 App() Component사용
    ```js
    ReactDOM.render(
    <React.StrictMode>
        <App />
    </React.StrictMode>,
    document.getElementById('root')
    );
    ```

- 새로운 Component 만들기

    /src/Potato.js 파일 생성후 코드 작성
    ```js
    import React from "react"; // import react

    // 대문자
    function Potato() {
        return <h3>I love Potato</h3>
    }

    export default Potato; // export this component
    ```

    index.js에서 작성한 ReactDom.render()에는 이미 App.js가 들어있는데, 한번에 여러 Component를 담을수는 없다.
    ```js
    ReactDOM.render(
        <React.StrictMode>
            <App />
        </React.StrictMode>,
        document.getElementById('root')
    ); // ReactDom은 하나의 Component만 render한다.
    ```

    그러므로 Potato.js는 App.js에 import
    ```js
    import React from 'react';
    import Potato from './Potato';

    function App() {
    return (
        <div>
        <h1>Helllllllo!!!!!!!!!</h1>
        <Potato />
        </div >
    );
    }

    export default App;
    ```
    이렇게 Component 안에 또다른 Component를 담아 render 할 수 있다.

    <img src="https://user-images.githubusercontent.com/66513003/127766710-f4a6f51e-513f-4f06-8493-450bef00772b.png" width="400">

___

## **JSX** 

- 다른 Componet로 데이터 보내기




## **React memo**

___


## **설치**
```
npx create-react-app movie_app (movie_app = 생성할 프로젝트명)
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

- 다른 Component로 데이터 보내기

     **App.js**
    ```js
    import React from 'react';

    // props객체로 받는 방법
    function Corn(p) {
    return (
        < div >
        <h1>I like {p.fav}</h1>
        </div >);
    }

    // props 객체의 fav만 바로 받는 방법
    function Potato({ fav }) {
    return (
        < div >
        <h1>I like {fav}</h1>
        </div >);
    }

    function App() {
    return (
        <div>
        <h1>Hello!!!!!!!!!</h1>
        <Potato fav="kimchi" />
        <Corn fav="Burger" />
        </div >
    );
    }

    export default App;
    ```

    #

    Array.map() 사용
    ```js
    var arr = ['Sushi', 'potato', 'Compost', 'Burger'];

    function Potato({ fav }) {
    return (
        <div>
        <h1>I like {fav}</h1>
        </div>);
    }

    function App() {

    return (
        <div>
        {arr.map(e =>
            <Potato fav={e} />
        )}

        </div>)
    }
    ```

    <img src="https://user-images.githubusercontent.com/66513003/127817724-998db2b2-60f8-41a2-9d4f-f7e1b022eddd.png" width="400">

___

- 여러 값 전송
    ```js
    import React from 'react';
    import PropTypes from 'prop-types';

    // 출력에 사용될 데이터
    const foodILike = [{
    id: 1,
    name: "Samgyeopsal",
    image: "https://3.bp.blogspot.com/-hKwIBxIVcQw/WfsewX3fhJI/AAAAAAAAALk/yHxnxFXcfx4ZKSfHS_RQNKjw3bAC03AnACLcBGAs/s400/DSC07624.jpg",
    rating: 4.9
    },
    {
    id: 2,
    name: "Bibimbap",
    image: "http://cdn-image.myrecipes.com/sites/default/files/styles/4_3_horizontal_-_1200x900/public/image/recipes/ck/12/03/bibimbop-ck-x.jpg?itok=RoXlp6Xb",
    rating: 4.8
    },
    {
    id: 3,
    name: "Doncasu",
    image: "https://s3-media3.fl.yelpcdn.com/bphoto/7F9eTTQ_yxaWIRytAu5feA/ls.jpg",
    rating: 5.5
    },
    {
    id: 4,
    name: "Kimbap",
    image: "http://cdn2.koreanbapsang.com/wp-content/uploads/2012/05/DSC_1238r-e1454170512295.jpg",
    rating: 4.7
    }
    ];

    // 받는 데이터를 jsx로 가공해 return
    function Potato({ name, rating, img }) {
    return (
        <div>
        <h4>{name}</h4>
        <span>★ {rating} / 5.0</span>
        <p><img src={img} alt={name} width='200px' /></p>
        </div>);
    }

    // 데이터 속성 검사
    Potato.propTypes = {
    name: PropTypes.string.isRequired, // string, 값이 반드시 존재
    image: PropTypes.string,
    rating: PropTypes.number,
    }

    // Potato에 데이터를 담아 return
    function renderFood(dish) {
    return <Potato key={dish.id} name={dish.name} img={dish.image} rating={dish.rating} />
    }

    // 전체 
    function App() {
    return (
        <div>
        {foodILike.map(renderFood)}
        </div>)
    } // map이 받는 foodILike의 데이터가 renderFood의 파라미터로 들어간다.

    export default App;
    ```

    <img src="https://user-images.githubusercontent.com/66513003/127855095-abe54ca1-eced-43c3-addf-5afdf88f37c6.png" width="400">

___

- 동적 데이터 처리를 위해 React.Component 상속, state 객체 사용

    ```js
    import React from 'react';

    // state 사용하기
    // 동적으로 갱신되는 데이터를 사용하기 위해
    class App extends React.Component {
    state = {
        count: 0
    }
    add = () => {
        this.setState((current) => { return { count: current.count + 1 } })
        // state를 직접 건드리지 않고 setState() 함수와 파라미터로 받는 데이터를 이용해 변경한다.
    }

    minus = () => {
        this.setState(current => ({ count: current.count - 1 }))
    }
    // 위의 add, minus함수는 그 자체로 render()를 refresh 하지 않는다.
    // setState() 함수를 호출할 때 마다 React가 render()를 재호출한다.
    // 데이터 갱신시, React는 바뀐부분(count)만 수정해 다시 출력하므로
    // HTML 화면의 바뀌는 부분이 깜빡이거나 하지 않는다.

    render() { // React.Component에 포함된 메소드
        return <div>
        <h1>Im a Class {this.state.count}</h1>
        <button onClick={this.add}>Add</button>
        <button onClick={this.minus}>Minus</button>
        </div>
    }
    }

    export default App;
    ```

    <img src="https://user-images.githubusercontent.com/66513003/127858817-98305db3-fd1e-4cbf-b567-a884694941cd.png" width="300">

    add, minus버튼을 누를때마다 숫자가 변경된다.
___

## **Component의 상태에 따라 실행되는 함수들**

    https://www.youtube.com/watch?v=ycOQk7SZWkM

- Mounting : Component가 생성됨
- Unmounting : Component가 죽음. 페이지가 바뀔 때, state로 Component를 교체할 때.
- Updating : Component가 변경됨


- Mounting 
    ```js
    class App extends React.Component
    ``` 
    로 객체 App이 생성되어 실행하면

    - **constructor()** : 생성자
    - *static getDerivedStateFromProps()* : ?
    - **render()** : Rendering Component
    - **componentDidMount()** : 어떤 Compnent가 처음으로 render 됐을 때

    순으로 실행된다.

- Updating
    setState()가 실행될때 순서대로 샐행되는 함수들 
    - *static getDerivedStateFromProps()* : ?
    - *shouldComponentUpdate()* : Component를 업데이트 할지 안할지 결정할 때 사용
    - **render()** : Render
    - *getSnapshotBeforeUpdate()* : ?
    - **componentDidUpdate()** : Component가 업데이트 됨

- Unmounting
    Component가 죽으면 실행되는 함수
    - **componentWillUnmount()** : Component가 떠날 때 호출 됨.

___

- 기존방식과 ES6 ECMA script 방식 차이
    ```js
    // 기존 방식
    const movies = await axios.get("https://yts-proxy.now.sh/list_movies.json")
    console.log(movies.data.data.movies)

    // ES6 ECMA script 방식
    const { data: { data: { movies } } } = await axios.get("https://yts-proxy.now.sh/list_movies.json")
    console.log(movies) // 받은 데이터(객체) 내부의 필요한 데이터만 저장할 수 있다
    ```

___
## **HTML과 JSX의 차이**

JSX에서는 JS의 class와 HTML의 class속성을 혼동할수 있기 때문에,  
HTML의 class는 **className**으로 작성한다.  
label 태그의 for도 JS의 for loop와 겹치기 때문에 **htmlFor**를 쓴다.

```jsx
<div className="myDiv"></div>
<label htmlFor="~~~"/>
```


___

## react app을 build하고 index.html이 동작하지 않을때 (빈페이지만 뜰 때)

- npm gh-pages를 쓰는 경우, package.json에서 homepage의 url을 "./"로 바꿔주면 된다.

```json
...
  },
  "homepage": "./"
}
```

___

## Fragment

- 컴포넌트를 <div>태그로 감싸는건 추첮되지 않는 방식
    ```js
    return (
        <div>
            ...
        </div>
    )
    ```

- 그래서 React에서는 HTML에서는 렌더링 되지 않는 Fragment라는 기능을 제공한다.
    ```js
    return (
        <>
            ...
        </>
    )
    ```

___

## **React this**

https://ljh86029926.gitbook.io/coding-apple-react/undefined/this

this는 선언 시점에서 결정되는 것이 아니고, 메소드/함수를 **어떤 주체**가 실행 하는지에 따라서 결정한다. 이를 무시할 수 있는 방법 중 하나는 bind를 사용해서 강제로 지정하는 방법이 있다.

### **.bind(실행 객체)**
this를 강제로 선언 시점에 고정해 두는 메소드

- 예제
    ```js
    const testObejct = {
        a: '12345',
        consoleA: function() {
            console.log(this.a);
        },
    };

    const globalConsoleA = testObejct.consoleA.bind(testObject);
    globalConsoleA(); // 12345
    ```

- 클래스 예제
    ```js
    class testClass {
    constructor() {
        this.a = '12345';
    }

    consoleA() {
        console.log(this.a);
    }
    }

    const testClassInstance = new testClass();
    testClassInstance.consoleA(); // 12345

    const globalConsoleA = testClassInstance.consoleA.bind(testClassInstance);
    globalConsoleA(); // 12345
    ```

___
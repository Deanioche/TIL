# **npm packages**

## **# prop-types**

https://www.npmjs.com/package/prop-types

```
npm i prop-types
```
Component에 사용되는 properties의 속성을 지정해 준다.

```js
import PropTypes from 'prop-types';

function Potato({ name, rating, img }) {
  return (
    <div>
      <h4>{name}</h4>
      <span>{rating}</span>
      <p><img src={img} alt={name} width='200px' /></p>
    </div>);
}

Potato.propTypes = {
  name: PropTypes.string.isRequired, // string, 값이 반드시 존재
  img: PropTypes.string,
  rating: PropTypes.number,
}
```
Potato의 파라미터로 들어오는 properties이 위 조건에 맞지 않으면 Warning을 발생시킨다.

<img src="https://user-images.githubusercontent.com/66513003/127852656-0187f768-9c5f-40ee-a7f3-7894665ac5d2.png" width="400">

___


## **# axios**

fetch()와 같음.  
API 받아오는 역할

```
npm i axios --save
```

axios.get("url")로 데이터를 받아오는 동안 async - await를 걸어준다.
```js
  getMovies = async () => {
    // axios로 API를 받아오는데 시간이 걸리므로 
    // 함수에 async를 걸어 await가 걸린 코드의 동작을 기다리게 한다.
    // JS는 비동기인데 await가 걸린 코드의 실행이 끝날 때까지 동기방식으로 바꿔준다.
    const movies = await axios.get("https://yts-proxy.now.sh/list_movies.json")
  }
```

___


## **# gh-pages**

github-page 도메인을 사용할 수 있게 해주는 모듈

```
npm i gh-pages --save
```

package.json 파일을 수정해야 한다.


1. homepage url 입력
    ```json
        ...
    },
    "homepage": "https://soksurim.github.io/movie-app" // github-page가 될 주소를 입력
    }
    //문서의 끝
    ```

2. deploy와 predeploy 커맨드 설정

    `"deploy": "gh-pages -d build"`   
    `"predeploy": "npm run build"`

    ```json
    ...
    "scripts": {
        "start": "react-scripts start",
        "build": "react-scripts build",
        "deploy": "gh-pages -d build",
        "predeploy": "npm run build" // 커맨드 이름에 pre- 가 붙으면 원래 커맨드(deploy) 호출시, predeploy가 앞서 실행된다.
    },
    ```

터미널에 "npm run deploy" 커맨드를 입력하면
먼저 predeploy 커맨드가 실행되어 프로젝트가 build 되고
그 다음에 deploy 명령어가 실행되어 github page에 업로드된다.

```
...
> movie_app@0.1.0 deploy
> gh-pages -d build

Published
```
터미널에 위처럼 뜨면 완료.

https://soksurim.github.io/movie-app 에서 확인이 가능하다.

___

## **# react router dom**

```
npm install --save react-router-dom
```

리액트에 라우터 기능을 넣어줌

____

## **# styled-components**

js에서 css를 작성할 수 있게 해준다.
아래와 같이 삼항연산자를 사용할 수도 있다.

- 설치
  ```
  npm i styled-components --save
  ```

```js
import styled from "styled-components";

const Button = styled.button`
  background: ${(p) => (p.primary ? "red" : "blue")};
`;

export default function App() {
  return (
    <div className="App">
      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>
      <Button primary>123</Button>
      <button>345</button>
    </div>
  );
}
```

간단한 컴포넌트 단위 CSS 작성에 유용

___


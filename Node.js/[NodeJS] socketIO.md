## **Socket.io**

___

**설치**
```js
npm install socket.io --save
```
___

**기본 코드**
```js
const server = require('http').createServer();
const io = require('socket.io')(server);
io.on('connection', client => {
  client.on('event', data => { /* … */ });
  client.on('disconnect', () => { /* … */ });
});
server.listen(3000);
```

___

**서버 코드**

```js
// 웹 서버
var express = require('express');
var app = express();

// socket.io
var server = require('http').createServer(app);
var io = require('socket.io')(server);

// static 폴더 지정
app.use(express.static(__dirname + '/'));

// url('/) 호출시
app.get('/', (req, res) => {
    res.render('index');    // 클라이언트에게 index.html 전달
})

// 클라이언트로부터 연결이 들어오면 실행되는 이벤트
io.on('connection', (socket) => {

    // socket 변수에는 실행 시점에 연결한 상대와 연결된 소켓의 객체가 들어있다.
    console.log('connected : ' + socket.id)

    //io.emit으로 전체 클라이언트에게 접속자 수 전송
    io.emit('usercount', io.engine.clientsCount);

    // 클라이언트 접속 해제시 이벤트 발생
    socket.on("disconnect", () => {
        console.log("Connection Lost")
        io.emit('message', '누구 나감');
        io.emit('usercount', io.engine.clientsCount);
    });

    // 클라이언트 -> 서버 메세지 수신 이벤트
    socket.on('message', (msg) => {

        //msg에는 클라이언트에서 전송한 매개변수가 들어온다. 이러한 매개변수의 수에는 제한이 없다.
        console.log('Message received: ' + msg);

        // io.emit으로 연결된 모든 소켓들에 신호를 보낼 수 있다.
        io.emit('message', msg);
    });
});

server.listen(8080, function () {
    console.log('Listening on http://localhost:8080/');
});

```

**클라이언트 코드**
```html
    <!-- 채팅창 -->
    <ul id="messages" type="none">
        <li id="usercount"></li>
    </ul>

    <form id="msgform">
        <input id="msginput" autocomplete="off" type="text">
        <button type="submit">전송</button>
    </form>
    
    <!-- JS -->
    <script src="/socket.io/socket.io.js"></script>
    <script>
        var socket = io();
        var msgform = document.getElementById('msgform');

        // socket.on 함수로 서버로부터의 신호를 수신
        socket.on('usercount', (count) => {
            var userCounter = document.getElementById('usercount');
            userCounter.innerText = "현재 " + count + "명이 서버에 접속해있습니다.";
        });

        // 메시지 수신시 HTML에 메시지 내용 작성
        socket.on('message', (msg) => {
            var messageList = document.getElementById('messages');
            var messageTag = document.createElement("li");
            messageTag.innerText = msg;
            messageList.appendChild(messageTag);
        });

        //채팅 보내기
        msgform.onsubmit = (e) => {
            e.preventDefault();
            var msginput = document.getElementById('msginput');

            // socket.emit으로 서버에 신호를 전달
            socket.emit('message', msginput.value);

            msginput.value = "";
        };
    </script>

```

___

**데이터 송수신**
- **emit** : 서버는 클라이언트에게로, 클라이언트는 서버에게로 데이터를 **보낸다**

- **on** : 서버는 클라이언트에게로, 클라이언트는 서버에게로 데이터를 **받는다**.




___

**# 참조** : https://socket.io/docs/v4/rooms/#Disconnection
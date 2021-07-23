# **MongoDB**

## **Initial setting**

```js
const bodyParser = require('body-parser'); // POST 데이터 교환
var express = require('express'); // 웹 서버
var mongoose = require('mongoose'); // MongoDB 연결

var app = express(); // express 내부 함수 사용
app.use(express.static(__dirname + '/')); // static 폴더 지정

// # BodyParser 세팅 - 참조 : https://www.npmjs.com/package/body-parser
app.use(bodyParser.json()) // for parsing application/json
app.use(bodyParser.urlencoded({ extended: true })) // for parsing application/x-www-form-urlencoded

// # Mongoose DB 연결
var url = 'mongodb+srv://[DB 주소]]?retryWrites=true&w=majority';
var option = { useNewUrlParser: true, useUnifiedTopology: true };
mongoose.connect(url, option);

var db = mongoose.connection;
db.on('error', console.error.bind(console, "connection error:"));
db.once('open', () => { console.log("DB connected " + Date().now); });

// 스키마 생성
var Schema = mongoose.Schema;

// 입력할 데이터 항목과 자료형 지정
var Memo = new Schema({
    author: String,
    contents: String,
    date: Date
});

// 생성할 모델의 모델명과 스키마 지정
var memoModel = mongoose.model('memo', Memo);
```

## **Data CRUD**

- **Index Page**
    ```js
    // static 폴더의 index.html 출력
    app.get('/', (req, res) => {
        res.render('index');

    })
    ```

- **Read**
    - server.js
        ```js
        app.get('/load', function (req, res, next) {
            // 모델의 데이터들을 받아옴
            memoModel.find({}, function (err, data) {
                // json parsing 해서 url('localhost:8080/load')로 전송
                res.json(data);
            });
        });
        ```

    - client.js
        ```js
            $.get('/load', function (data) {
                $("#memo").empty(); // HTML의 데이터 출력될 부분을 초기화

                $(data).each(function (i) {  // DB로 부터 받은 메모리스트(data) foreach로 출력 

                    // 데이터 각각의 고유 id 저장
                    var id = this._id;

                    // string으로 받은 시간을 Date 객체로 변환 + 한국시간
                    var date = new Date(this.date).toLocaleTimeString('ko-KR'); 

                    // 데이터 HTML 틀에 맞춰 출력
                    $("#memo").prepend("<div class='item'></div>");
                    $("#memo .item:first").append("<div class='photo_thumb'></div>");
                    $("#memo .item:first").append(`
                        <div class='author'>
                            <b>${this.author}</b> (${date}) &nbsp; &nbsp; 
                            <span class='text_button modify'>MODIFY</span> 
                            <span class='text_button del'>DELETE</span> 
                            <span class='index'> ${(i + 1)} </span> 
                        </div>`);
                    $("#memo .item:first").append("<div class='contents " + id + "'>" + this.contents + "</div>");

                    // 위에 출력된 modify 버튼에 클릭리스너 지정
                    var memo = this.contents;

                    $("#memo .item:first .modify").click(function (evt) {  // modify 버튼이 눌러졌을 때

                        $("#memo ." + id).html("<textarea id='textarea_" + id + "' class='textarea_modify'>" + memo + "</textarea>");

                        // Enter 키 이벤트 지정
                        $("#textarea_" + id).keypress(function (evt) {
                            if ((evt.keyCode || evt.which) == 13) { 
                                if (this.value != "") {
                                    modify(this.value, id);
                                    evt.preventDefault();
                                }
                            }
                        });
                    });

                    // 위에 출력된 del 버튼에 클릭리스너 지정
                    $("#memo .item:first .del").click(function (evt) { 
                        del(id);
                    });
                });
            });
        ```

- **Create**

    
    - client.js
        ```js
        // 클라이언트에서 데이터 입력
        write = function () {
            
            // 유효성 검사
            if ($('input[type = "author"]').val() == "" || $(".memoForm textarea").val() == "") {
                return
            }

            // 입력한 데이터로 객체 생성
            var postdata = {
                'author': $('input[type = "author"]').val(),
                'contents': $(".memoForm textarea").val()
            };
            
            $('input[type = "author"]').val("");
            $(".memoForm textarea").val("");

            // 데이터를 url(localhost:8080/write)로 post 전송
            $.post('/write', postdata, function () {
                
                load(); // Read 동작
            });
        };
        ```

    - server.js
        ```js
        // localhost:8080/write로부터 데이터 수신
        app.post('/write', function (req, res, next) {
            
            // request의 body 객체에 담긴 데이터로 변수 생성
            var author = req.body.author;
            var contents = req.body.contents;
            var date = Date();

            var memo = new memoModel(); // 모델 생성 후 데이터 입력

            memo.author = author;
            memo.contents = contents;
            memo.date = date;
            memo.comments = [];
        
            // 모델을 DB로 전송
            memo.save(function (err) {
                if (err) {
                    throw err;
                }
                else {
                    res.json({ status: "SUCCESS" });
                }
            });

        });
        ```

- **Update**
    
    - client.js
        ```js
        // 메모 수정
        modify = function (contents, id) {

            // 수정한 내용과 해당 메모의 고유 id를 담을 객체 생성
            var postdata = {
                'author': $('input[type = "author"]').val(),
                'contents': contents,
                '_id': id
            };

            // 설정된 url로 객체 post 전송
            $.post('/modify', postdata, function () {
                load();
            });
        };
        ```

    - server.js
        ```js
        app.post('/modify', function (req, res, next) {

            // 받은 데이터 저장
            var _id = req.body._id;
            var contents = req.body.contents;

            // findOne()의 첫번째 파라미터로 찾을 데이터의 조건 지정 (= sql의 where문)
            memoModel.findOne({ _id: _id }, function (err, memo) {
                if (err) {
                    throw err;
                }
                else {
                    // 조건에 맞는 데이터를 DB로 부터 받아와(memo) 수정한 내용으로 덮어씌운다.
                    memo.contents = contents;

                    // DB에 저장
                    memo.save(function (err) {
                        if (err) {
                            throw err;
                        }
                        else {
                            res.json({ status: "SUCCESS" });
                        }
                    });
                }
            });
        });
        ```

- **Delete**
    
    - client.js
        ```js
        del = function (id) {

            // 객체에 id만 담아
            var postdata = {
                '_id': id
            };

            // 해당 url로 전송
            $.post('/del', postdata, function () {
                load();
            });
        };
        ```

    - server.js
        ```js
        // 삭제
        app.post('/del', function (req, res, next) {
            var _id = req.body._id;

            // 조건에 맞는 데이터 삭제
            memoModel.deleteOne({ _id: _id }, function (err, result) {
                if (err) {
                    throw err;
                }
                else {
                    res.json({ status: "SUCCESS" });
                }
            });
        });
        ```

___

**# Memo**

- 조건에 맞는 document 전부 삭제
    ```js
    memoModel.deleteMany({ contents: 'hangover' });
    ```

- 댜수 DB 연결방법
    ```js
    var mongoose = require('mongoose');
    var connection1 = mongoose.createConnection('mongodb://localhost/mydb1');
    var connection2 = mongoose.createConnection('mongodb://localhost/mydb2');
    ```

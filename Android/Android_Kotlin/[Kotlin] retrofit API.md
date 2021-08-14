# **retrofit**

코틀린과 Node.js 서버 통신하기 위한 라이브러리
JS의 Axios, Fetch API와 같은 기능

- 설치

```js
// build.gradle (Module)

dependencies {
    ...
    implementation 'com.squareup.retrofit2:retrofit:2.9.0'
    implementation 'com.squareup.retrofit2:converter-gson:2.8.2'
    ...
}
```
retrofit과 JSON파일을 GSON 파일로 변환하기위한 dependency 추가

build.gradle (Module)이 아닌, build.gradle (Project)에 추가하지 않도록 주의.

- ## **Node.js 서버**

    ```js
    var express = require('express')
    var http = require('http');
    var app = express();
    var bodyParser = require('body-parser')

    app.use(bodyParser.urlencoded({ extended: false }))
    app.get(`/`, (req, res) => {
        console.log(req.query);
        res.send({ "result": "GET 호출" });
    })

    app.post(`/`, (req, res) => {
        var { id, nick, pwd } = req.body;
        console.log("POST " + id, nick, pwd);
        res.send({ "result": "POST 호출", "data": { id, nick, pwd } });
    })

    app.put(`/:id`, (req, res) => {
        console.log(`내용 PrimaryKey : ${req.params.id}`)
        console.log(req.body);
        res.send({ "result": "UPDATE 호출" });
    })

    app.delete(`/:id`, (req, res) => {
        console.log(req.params.id);
        console.log(req.path)
        res.send({ "result": "DELETE 호출" });
    })

    app.listen(2777, () => {
        console.log(`서버 실행, 포트 번호 2777`);
    });
    ```

- ## **APIInterface.kt**

    - Node.js 서버 -> Kotlin으로 보내지는 데이터를 받기위한 data class
        ```kt
        data class ResponseDC(
            var result: Any? = null,
            var data: ResponseJson? = null
        )

        data class ResponseJson(
            var id: Number? = null,
            var pwd: String? = null,
            var nick: String? = null
        )
        ```
        위와 같은 틀(DTO)이 있어야 데이터를 받아 사용할 수 있다.

    - Kotlin -> Node.js 데이터 전송
        ```kt
        interface APIInterface {

            @GET("/")
            fun getRequest(@Query("name") name: String): Call<ResponseDC>

            // POST 방식 1 각각 보내기
            @FormUrlEncoded
            @POST("/")
            fun postRequest(
                @Field("id") id: Number,
                @Field("pwd") password: String,
                @Field("nick") nick: String
            ): Call<ResponseDC>

            // POST 방식 2 JSON
            @POST("/")
            @Headers("accept: application/json", "content-type: application/json")
            fun postRequest(
                @Body params: Map<String, String> // 왜 앙대
            ): Call<ResponseDC>

            @FormUrlEncoded
            @PUT("/{id}")
            fun putRequest(
                @Path("id") id: String, // url로 감
                @Field("content") content: String
            ): Call<ResponseDC>

            @DELETE("/{id}")
            fun deleteRequest(@Path("id") id: String): Call<ResponseDC>
        }
        ```

- ## **MainActivity.kt**


    - 접속할 ip 주소와 retrofit 객체 초기화
        ```kt
        val url = "ip 주소" 

        val retrofit = Retrofit.Builder()
            .baseUrl(url)
            .addConverterFactory (GsonConverterFactory.create())
            .build()
        var server = retrofit.create(APIInterface::class.java)
        ```

    


    - 서버와 데이터 송수신
        ```kt
        binding.buttonGET.setOnClickListener { // 버튼 리스너

            server.getRequest("surimi").enqueue(object : Callback<ResponseDC> { 
                override fun onFailure(call: Call<ResponseDC>, t: Throwable) {
                    Log.d("failure : ", t?.message.toString())
                }

                override fun onResponse(call: Call<ResponseDC>, response: Response<ResponseDC>) {
                    Log.d("response : ", response?.body().toString())
                }

            })

        // 서버로 GET 방식으로 문자열 "surimi"를 전송하고
        // 서버로부터 돌어오는 데이터를 ResponseDC 객체에 담아 Log로 출력
        }

        binding.buttonPOST.setOnClickListener {

            val map = HashMap<String, Any>()
            map.put("id", 0)
            map.put("pwd", "123")
            map.put("nick", "surimi")
            // HashMap에 전송할 데이터를 담아둠

            server.postRequest(map["id"] as Number, map["pwd"] as String, map["nick"] as String).enqueue((object : Callback<ResponseDC> { 
        // postRequest에 전송할 데이터를 담아 전송 

                override fun onResponse(
                    call: Call<ResponseDC>,
                    response: Response<ResponseDC>
                ) {
                    Log.d("response : ", response?.body().toString())
                    println(response?.body()?.data)
                    println(response?.body()?.data?.id)
                    println(response?.body()?.data?.pwd)
                    println(response?.body()?.data?.nick)
                }

                // 서버로부터 ResponseDC 객체 형태의 데이터를 받아 그 안의 데이터를 출력해보기

                override fun onFailure(call: Call<ResponseDC>, t: Throwable) {

                }

            }))
        }
        binding.buttonUPDATE.setOnClickListener {
            server.putRequest("board", "내용").enqueue((object : Callback<ResponseDC> {
                override fun onFailure(call: Call<ResponseDC>, t: Throwable) {

                }

                override fun onResponse(call: Call<ResponseDC>, response: Response<ResponseDC>) {
                    Log.d("response : ", response?.body().toString())
                }
            }))
        }
        binding.buttonDELETE.setOnClickListener {
            server.deleteRequest("board").enqueue((object : Callback<ResponseDC> {
                override fun onFailure(call: Call<ResponseDC>, t: Throwable) {

                }

                override fun onResponse(call: Call<ResponseDC>, response: Response<ResponseDC>) {
                    Log.d("response : ", response?.body().toString())
                }
            }))
        }
        ```
    

____

# Kotlin - retrofit API <-> NodeJS 서버 데이터 전송시 서버가 빈 객체를 받는 문제

- 코틀린 retrofit API로 HashMap 객체 POST 전송

- **Retrofit Interface.kt**
    ```kt
    @POST("/")
    @Headers("accept: application/json", "content-type: application/json")
    fun postRequest(
        @Body params: Map<String, String> 
    ): Call<ResponseDC>
    ```

- **MainActivity.kt**
    ```kt
    // Hashmap 객체 생성
    val map = HashMap<String, String>()
    map.put("id", "0")
    map.put("pwd", "123")
    map.put("nick", "surimi")

    // 서버로 전송
    server.postRequest(map).enqueue((object : Callback<ResponseDTO> {
        override fun onResponse(
            call: Call<ResponseDTO>,
            response: Response<ResponseDTO>
        ) {
            Log.d("response : ", response?.body().toString())
            println(response?.body()?.data)
            println(response?.body()?.data?.id)
            println(response?.body()?.data?.pwd)
            println(response?.body()?.data?.nick)
        }

        override fun onFailure(call: Call<ResponseDC>, t: Throwable) {

        }
    }
    ```

- **NodeJS Server.js**
    ```js
    app.post(`/`, (req, res) => {
        var { id, nick, pwd } = req.body;
        console.log("POST " + id, nick, pwd);
        res.send({ "result": "POST 호출", "data": { id, nick, pwd } });
    })
    ```
    post로 받은 데이터가 담기는 req.body를 찍어보면 body 객체안에는 아무것도 담겨있지 않았는데, 

    ```js
    var bodyParser = require('body-parser')

    app.use(bodyParser.urlencoded({ extended: false }))
    app.use(bodyParser.json()) // for parsing application/json
    ```
    body parser 설정이 제대로 되어있지 않았다.

    고쳐주니 해결.

___
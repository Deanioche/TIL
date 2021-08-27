## **HTTP GET Request in JS**

#

- use XMLHttpRequest object
    ```js
    httpGetAsync('/load', (data) => {
        console.log(JSON.parse(data))
    })

    function httpGetAsync(theUrl, callback) {
        var xmlHttp = new XMLHttpRequest();
        xmlHttp.onreadystatechange = function () {
            if (xmlHttp.readyState == 4 && xmlHttp.status == 200)
                callback(xmlHttp.responseText);
        }
        xmlHttp.open("GET", theUrl, true); // true for asynchronous 
        xmlHttp.send(null);
    }
    ```

- Simple
    ```js
    const http = new XMLHttpRequest()

    http.open("GET", "/load")
    http.send()

    http.onload = () => console.log(JSON.parse(http.responseText))
    ```

- Fetch API (IE not supported)
    ```js
    fetch(url).then(function(response) {
    return response.json();
    }).then(function(data) {
    console.log(data);
    }).catch(function() {
    console.log("Booo");
    });
    ```

- Fetch in ES7
    ```js
    console.log(fetchAsync('/load'))

    async function fetchAsync(url) {
        let response = await fetch(url);
        let data = await response.json();
        return data;
    }
    ```


- In Jquery
    ```js
    var page_content;
    $.get( "somepage.php", function(data){
        page_content = data;
    });
    ```
- Ajax (need Jquery)
    ```js
    $.ajax({
        url: '/load', //request 보낼 서버의 경로
        type: 'get', // 메소드(get, post, put 등)
        success: function (data) {
            //서버로부터 정상적으로 응답이 왔을 때 실행

            console.log(data)
        },
        error: function (err) {
            //서버로부터 응답이 정상적으로 처리되지 못햇을 때 실행
            console.log(err)
        }
    });
    ```

**# 출처 : https://stackoverflow.com/questions/247483/http-get-request-in-javascript**
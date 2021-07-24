## Error

___
[Express, Mongoose]
**# Error [ERR_HTTP_HEADERS_SENT]: Cannot set headers after they are sent to the client**


- 한 라우터(app.get('/')) 요청에 다수의 응답(res.send() 등)이 보내져서 발생하는 에러.

___


[pug]

- 해당 경로에 파일이 존재하지 않음
```
Error: Failed to lookup view "main" in views directory "d:\dev\Repositiory\Sandbox\NodeJS\SocketBingo\views"
```

- extends는 코드 최상단에 위치해야됨
```
Declaration of template inheritance ("extends") should be the first thing in the file. There can only be one extends statement per file.  
```
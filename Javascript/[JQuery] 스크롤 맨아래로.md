## 스크롤 최하단으로 내리기

https://github.com/Soksurim/Sandbox/blob/main/Javascript/Chatroom/script.js 참고

### JavaScript
```javascript
  var logPanel = document.querySelector(".showJson");
  logPanel.scrollTop = logPanel.scrollHeight;
```
### JQuery
```javascript
  $("div").scrollTop(
    $("div").prop("scrollHeight")
  );
```
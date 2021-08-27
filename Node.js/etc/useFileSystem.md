## **use fs**

___

- readFile

    ```js
    var fs = require('fs');

    console.log(1)
    fs.readFile(__dirname + '/index.html', { encoding: 'utf8' }, (err, data) => {
        console.log(data)
    });
    console.log(2)
    ```
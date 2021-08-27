## **NodeJS input 받는 방법들**

ref: https://nodejs.dev/learn/accept-input-from-the-command-line-in-nodejs
___

- **readline 사용**
    question에 대한 input을 한줄 받음.
    ```js
    const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
    })

    readline.question(`What's your name?`, name => {
    console.log(`Hi ${name}!`)
    readline.close()
    })
    ```

    한 줄을 입력받고 close처리
    ```js
    const readline = require('readline');

    const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
    });

    rl.on('line', function(line) {
    console.log(line); //입력 값을 처리할 callback 내용 기제

    rl.close(); //callback 종료
    }).on("close", function() {
    process.exit(); // 출력과 관련된 내용 기재 (console.log같은거..)
    });
    ```

    여러 줄을 입력받고 Ctrl + D로 입력 끝내기
    ```js
    const rl = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
    });

    let input = [];

    rl.on('line', function (line) {
        input.push(line);

    }).on('close', function () {
            console.log(input);
            process.exit();
        });
    ```

- **inquirer 사용**

    npm install inquirer 후,
    ```js
    const inquirer = require('inquirer')

    var questions = [
    {
        type: 'input',
        name: 'name',
        message: "What's your name?"
    }
    ]

    inquirer.prompt(questions).then(answers => {
    console.log(`Hi ${answers['name']}!`)
    })
    ```
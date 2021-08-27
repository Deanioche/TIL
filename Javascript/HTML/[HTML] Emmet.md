**Emmet**

- HTML에서 여러줄의 코드를 한번에 입력하는 방법

- HTML 기본 템플릿
    ```html
    !

    <!DOCTYPE html>
    <html lang="en">
        <head>
            ...
    ```

- 태그 여러개 
    ```html
    div*4 입력

    <div></div>
    <div></div>
    <div></div>
    <div></div>
    ```

- 중첩 태그
    ```html
    div>ul>li 입력

    <div>
        <ul>
            <li></li>
        </ul>
    </div>
    ```

- 인접 태그
    ```html
    div+h1+h2 입력

    <div></div>
    <h1></h1>
    <h2></h2>
    ```

- id & class 설정
    ```html
    div.class#id 입력

    <div class="class" id="id"></div>
    ```

- 텍스트 삽입
    ```html
    input:btn.myBtn{click me}

    <input type="button" value="" class="myBtn">click me</input>
    ```

- 숫자 삽입
    ```html
    div.class$*4

    <div class="class1"></div>
    <div class="class2"></div>
    <div class="class3"></div>
    <div class="class4"></div>

    # 변형
    tr>td#0$0$*4
    <tr>
        <td id="0101"></td>
        <td id="0202"></td>
        <td id="0303"></td>
        <td id="0404"></td>
    </tr>
    ```

- 중첩 태그에서 상위로 이동
    ```html
    div>p>pp^p2>pp2>ppp2^^p3>pp3
    ^ 하나당 상위 태그로 한칸 올라감
    <div>
        <p>
            <pp></pp>
        </p>
        <p2>
            <pp2>
                <ppp2></ppp2>
            </pp2>
        </p2>
        <p3>
            <pp3></pp3>
        </p3>
    </div>

    div>((p>pp)+(p2>pp2>ppp2)+(p3>pp3)) 와 같음
    ```

- 그룹화
    ```html
    div>((p>pp)+(p2>pp2>ppp2)+(p3>pp3))

        <div>
        <p>
            <pp></pp>
        </p>
        <p2>
            <pp2>
                <ppp2></ppp2>
            </pp2>
        </p2>
        <p3>
            <pp3></pp3>
        </p3>
    </div>
    ```

- 예
    ```html
    table#board>(tr>td#0$*4)+(tr>td#1$*4)+(tr>td#2$*4)+(tr>td#3$*4)

    <table id="board">
        <tr>
            <td id="01"></td>
            <td id="02"></td>
            <td id="03"></td>
            <td id="04"></td>
        </tr>
        <tr>
            <td id="11"></td>
            <td id="12"></td>
            <td id="13"></td>
            <td id="14"></td>
        </tr>
        <tr>
            <td id="21"></td>
            <td id="22"></td>
            <td id="23"></td>
            <td id="24"></td>
        </tr>
        <tr>
            <td id="31"></td>
            <td id="32"></td>
            <td id="33"></td>
            <td id="34"></td>
        </tr>
    </table>
    ```
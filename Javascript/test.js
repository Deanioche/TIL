function A(n, a) {
    console.log(n, a);
}

const a = new A();

//console.log(a, typeof a);

const bb = 5

{
const bb = 3 + 5
console.log(bb)

}
console.log(bb);

(function() {
    console.log("즉시 실행 함수")
})()

let x = function(){
    console.log("x 익명 함수")
    return "[x() 리턴값]"
}

console.log("x() 실행 결과 : " + x())

let y = function ss(){
    console.log("y 기명 함수 ss")
    return "[y() 리턴값]"
}

console.log("y() 실행 결과 : " + y())

function alert(msg) {
  console.log(msg)
}

const myObj = function (a, b) { 
  this.a = a;
  this.b = b;
  this.c = function (a, b) {
    return `${this.a}, ${this.b}`
  }
}

const cc = new myObj(3, 4)

console.log(cc.c(1,2))


let user = {
  name: "John",
  age: 30,

  sayHi() {
    // 'this'는 '현재 객체'를 나타냅니다.
    alert(this.name);
  }

};

user.sayHi(); // John

user = {
  name: "Mike",
  sayHi() {
  alert(this.name);
}}

user.sayHi(); 
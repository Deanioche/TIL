// 함수 호출 전
let menu = {
  width: 200,
  height: 300,
  title: "My menu"
};

var multiplyNumeric = function (val) {
    
    for (let i in val) {
        if (typeof val[i] == 'number') {
            val[i] *= 2
        }
    }
    
}

multiplyNumeric(menu);

console.log(menu)
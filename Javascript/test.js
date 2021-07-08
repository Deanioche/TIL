function A(name, age) {
    this.name = name
    this.hello = function(age) {
         console.log('hello!')
         return age
    }
}

const aa = new A('Din', 23)
console.log(aa.name)
console.log(aa.hello())

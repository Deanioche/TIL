function A(name) {
    this.name = name
    this.hello = function(name) {
         return `hello, ${name}\!`
    }
}

const aa = new A('Din', 23)
console.log(aa.name)
console.log(aa.hello('Joe'))

// Din
// hello, Joe!
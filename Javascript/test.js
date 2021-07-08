function fun1(fun, n){
    console.log('hello')
    n++
    fun(n)
}

fun1(function(n){
    console.log('funny!', n)
}, 3)

// hello
// funny! 4
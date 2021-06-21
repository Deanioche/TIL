const me = {
    name : 'Fin',
    job : 'unemployed',
    age : 15,
    say : function say() { // input function into object
        console.log(`I'm ${this.job}!`)
    },
    why(){ // short
        console.log(`I'm only ${this.age} years old!`)
    },
    get info() {
        console.log('get info() 동작')
        return [this.name, this.job, this.age]
    },

    
    /**
     * @param {string} name
     */
    set setName(name) { // cannot be existed name
        console.log('setName() 동작')
        this.name = name
    }
} 

console.log(me.info) // [ 'Fin', 'unemployed', 15 ]
me.setName = 'Hoo'

console.log(me.info) // [ 'Hoo', 'unemployed', 15 ]
const names = ['James', 'Anna', `Berlin`, `Mina`];

function print(names){
    console.log(names);
}

names.forEach(print); // array 'names'

names.forEach((names, index, array, c, d) => {
    console.log(index, names, array);
}); // array 'names'
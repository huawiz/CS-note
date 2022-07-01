function f_rec(n){
    return n < 3?n:f_rec(n-1)+2*f_rec(n-2)+3*f_rec(n-3);
}
console.log(f_rec(5));

function f_iter(n){
    return n<3?n:f_iter_imp(2,1,0,n-2);
}

function f_iter_imp(a,b,c,count){
    return count == 0 ? a : f_iter_imp(a+2*b+c*3,a,b,count-1);
}

console.log(f_iter(5));
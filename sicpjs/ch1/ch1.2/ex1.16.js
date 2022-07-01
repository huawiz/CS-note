

function fast_expt(b,n){
    function is_even(x){
        return x % 2 === 0 ? true : false;
    }
    function fast_expt_iter(a,b,n){
        return n === 0
            ? a
            : is_even(n)
                ? fast_expt_iter(a,b*b,n/2)
                : fast_expt_iter(a*b,b,n-1);
    }

    return fast_expt_iter(1,b,n);
}

console.log(fast_expt(2,5));
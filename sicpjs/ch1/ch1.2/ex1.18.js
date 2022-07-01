function double(x){return x+x;}
function half(x){return x/2;}
function is_even(x){return x % 2 ===0? true:false;}
function times_iter(total,a,b){
    return b === 1
            ? total  + a
            :a === 0 || b === 0
                ? 0
                :is_even(b)
                    ? times_iter(total,double(a),half(b))
                    : times_iter(total+a,a,b-1);
}

function times(a,b)
{
    return times_iter(0,a,b);
}

console.log(times(2,3));




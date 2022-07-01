
function double(x){return x+x;}
function half(x){return x/2;}
function is_even(x){return x %2 ===0? true:false;}
function times(a,b)
{
    return b===1
            ?a
            :a===0||b===0
                ?0
                :is_even(b)
                    ?double(times(a,half(b)))
                    :a+times(a,b-1);
}

console.log(times(2,3));

function cube_root(guess,x)
{ 
    return is_good_enough(guess,x)
            ?guess
            :cube_root(improve(guess,x),x);
}

function is_good_enough(guess,x)
{
    console.log("x ",x," guess ",guess," improve ",improve(guess,x));
    //return abs(cube(guess)-x) < 0.001;
    return abs(guess-improve(guess,x))/improve(guess,x) < 0.001;
}

function abs(x){return x>0?x:-x;}
function cube(x){return x*x*x;}
function div3(x,y){return (x+y)/3;}

function improve(guess,x)
{
    return div3(x/(guess*guess),guess*2);
}

function sqrt_cube(x){return cube_root(1,x);}

const num = 122763473;
console.log(sqrt_cube(num));

//Internal
//因為我們喜歡把一些作為判斷(例如is_good_enough)的函數用在其中一函數的功能上
//，如果程式一大，那可能會需要很多個類似的判斷函數，這樣命名上會有困難，
//其實我們可以利用Internal function，在函數裡面寫函數，用區域特性來寫，
//如此一來，除了可以減少參數的引入(例如sqrt的x可以直接通用，不用在每個代表同樣意義的函數引入)
function sqrt(x){
    
    function sqrt_iter(guess)
    {
        return  is_good_enough(guess)
                    ?guess
                    :sqrt_iter(improve(guess,x))
    }

    function improve(guess)
    {
        return average(guess,x/guess);
    }
    function is_good_enough(guess)
    {
        console.log("x ",x," guess ",guess," improve ",improve(guess,x));
        return abs(guess-improve(guess,x))/improve(guess,x) < 0.001;
    }

    function average(x,y)
    {
        return (x+y)/2;
    }
    function abs(x)
    {
        return x>0?x:-x;
    }
    function square(x)
    {
        return x*x;
    }
    return sqrt_iter(1);
}

const num = 0.000000000625;
console.log(num,'的平方根是',sqrt(num));

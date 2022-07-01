//照著牛頓法定義，如果夠相近就印出，否則就繼續
function sqrt_iter(guess,x)
	{
	return  is_good_enough(guess,x)
					?guess
					:sqrt_iter(improve(guess,x),x)
	}
//每一步近似，都是guess和x/guess取平均
function improve(guess,x){return average(guess,x/guess);}

//設立一個近似的終點，避免疊代無限loop

function is_good_enough(guess,x){console.log("x ",x," guess ",guess," improve ",improve(guess,x));return abs(guess-improve(guess,x))/improve(guess,x) < 0.001;}

//補足數學工具:平均、絕對值、平方
function average(x,y){return (x+y)/2;}
function abs(x){return x>0?x:-x;}
function square(x){return x*x;}

//透過我們自製的牛頓法，做出近似根植的函數
function sqrt(x){return sqrt_iter(1,x);}

const num = 0.000000000625;
console.log(num,'的平方根是',sqrt(num));

/*如果把`sqrt_iter`用函數`condition`包著會發生甚麼事呢?

答案: 如同前述 Applicative-order 函數(function or procedure) 會優先判讀parameter，當他判讀到sqrt_iter帶有遞迴時，就會產生無限loop */
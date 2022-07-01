function pascal(row,index){
    return index>row?false
    :index==1||index==row   //設定row=1/index=1時的情況
        ?1
        :pascal(row-1,index-1)+pascal(row-1,index);
}

console.log(pascal(5,2));
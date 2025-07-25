/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSum = function(nums) {
    let arr = [];
    let arr2 = []
    for(o of nums){
        if(o>=0){
            if(arr.indexOf(o)==-1)
                arr.push(o);
        }
        else {
            if(arr2.indexOf(o)==-1)
                arr2.push(o);
        }
    }
    let s = 0;
    if(arr.length>0) {
        for(j of arr)
            s+=j;
    }
    else{
        s = Math.max(...arr2)
    }
    return s


};
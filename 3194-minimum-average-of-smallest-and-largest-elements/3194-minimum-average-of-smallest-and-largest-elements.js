/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumAverage = function(nums) {
    nums.sort((a,b)=>a-b)
    let arr =[]
    while(nums.length > 1){
       
        arr.push((nums.pop()+nums.shift())/2)
    }
    return Math.min(...arr)
};
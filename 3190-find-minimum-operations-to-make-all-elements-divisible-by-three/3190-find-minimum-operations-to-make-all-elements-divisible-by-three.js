/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    let count = 0;
    for(const num of nums){
        if(num%3!==0){
            if((num-1) % 3 === 0 || (num + 1) % 3=== 0){
                count++;
            }else {
                count+=2;
            }
        }
    }
    return count;
};
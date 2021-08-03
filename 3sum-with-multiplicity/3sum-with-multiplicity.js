/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var threeSumMulti = function(arr, target) {
    const max = 1000000007;
    let count = 0;
    function twoSumCount(arr, pos, target){
        let hash = {}, count = 0;
        for(let i=pos; i<arr.length; i++){
            if(hash[arr[i]]){
                count += hash[arr[i]];
            }
            if(!hash[target-arr[i]]){
                hash[target-arr[i]] = 0;
            } 
            hash[target-arr[i]]++;
            
            
        }
        return count;
    }
    for(let i=0; i<arr.length-1; i++){
        count += twoSumCount(arr, i+1, target-arr[i]);
        count %= max;
    }
    return count;
};
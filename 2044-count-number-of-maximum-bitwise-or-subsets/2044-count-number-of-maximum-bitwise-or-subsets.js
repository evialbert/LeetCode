/**
 * @param {number[]} nums
 * @return {number}
 */
var countMaxOrSubsets = function(nums) {
    let maxOr=nums.reduce((a,i)=>a|i);
    let count=0;
    function countSubarrays(idx,curr){
        if(idx>=nums.length){
            if(curr===maxOr) return 1
            else return 0
        }
        let pick=countSubarrays(idx+1,curr | nums[idx]);
        let notPick=countSubarrays(idx+1,curr);
        return pick+notPick

    }
    return countSubarrays(0,0)
    
};
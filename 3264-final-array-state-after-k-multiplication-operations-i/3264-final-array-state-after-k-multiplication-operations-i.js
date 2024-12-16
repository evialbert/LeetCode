/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} multiplier
 * @return {number[]}
 */
const getMinInd = (arr) => {
    let minInd = 0;
    for(let i=1;i<arr.length;i++) if(arr[i] < arr[minInd]) minInd = i;
    return minInd;
}

const getFinalState = function(nums, k, multiplier) {
    for(let i=0;i<k;i++){
        const minInd = getMinInd(nums);
        nums[minInd] = nums[minInd] * multiplier;
    }
    return nums;
};
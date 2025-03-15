/**
 * @param {number[]} nums
 * @return {number[]}
 */
var largestDivisibleSubset = function(nums) {
    let n = nums.length, max = 1, lastIdx = 0;
    let dp = new Array(n).fill(1);
    let hash = new Array(n);
    nums.sort((a,b)=>a-b);
    for(let idx = 0; idx < n; idx++) {
        hash[idx] = idx;
        for(let prev = 0; prev < idx; prev++) {
            if(nums[idx] % nums[prev] == 0 && dp[idx] < dp[prev] + 1) {
                dp[idx] = dp[prev] + 1;
                hash[idx] = prev;
            }
        }
        if(max < dp[idx]) {
            max = dp[idx];
            lastIdx = idx;
        }
    }
    let lds = new Array(max);
    lds[--max] = nums[lastIdx];
    while(hash[lastIdx] != lastIdx) {
        lastIdx = hash[lastIdx];
        max--;
        lds[max] = nums[lastIdx];
    }
    return lds;
};
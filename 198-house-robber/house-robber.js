/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if(!nums) return 0;
    // let dp = {}
    // return solve(0);

    // function solve(index){
    //     if(index >= nums.length){
    //         return dp[index] = 0;
    //     }
    //     if(dp[index]) return dp[index]
    //     let one = nums[index]+solve(index+2);
    //     let two = solve(index+1);
    //     return dp[index] = Math.max(one,two)
    // }

    let dp = Array(nums.length+2).fill(0);

    for(let i=nums.length-1;i>=0;i--){
        let one = nums[i] + dp[i+2];
        let two = dp[i+1];
        dp[i] = Math.max(one,two);
    }

    return dp[0];

    // console.log(dp);
    // return dp[nums.length-1];

    // let one =0;
    // let two = 0
    // for(let i = nums.length-1;i>=0;i--){
    //     let temp = Math.max(nums[i] + one,two);
    //     one = two;
    //     two = temp;
        
    // }
    // return two;
};
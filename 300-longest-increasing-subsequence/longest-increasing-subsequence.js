/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    var n = nums.length;
    if (!n) return 0;
    var len = 1;
    var dp = [nums[0]];
    for (var i = 1; i < n; i++) {
        if (dp[len - 1] < nums[i]) {
            dp[len++] = nums[i];
        } else {
            var left = 0, right = len - 1, num = nums[i];
            while (left < right) {
                var mid = left + Math.floor((right - left) / 2);
                if (dp[mid] < num) left = mid + 1;
                else right = mid;
            }
            dp[right] = num;
        }
    }
    return len;
};
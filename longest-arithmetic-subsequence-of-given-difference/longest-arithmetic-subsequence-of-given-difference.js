/**
 * @param {number[]} arr
 * @param {number} difference
 * @return {number}
 */
const longestSubsequence = (arr, difference) => {
    let maxLen = 0;
    
    if (difference < 0) {
        arr = arr.reverse();
        difference *= -1;
    }
    
    const hashMap = new Map([[arr[0], 0]]);
    const dp = [1];
    for (let i = 1; i < arr.length; i++) {
        const prevMatch = hashMap.get(arr[i] - difference);
        
        
        if (prevMatch !== undefined) {
            dp[i] = dp[prevMatch] + 1;
        } else {
            dp[i] = 1;
        }
        
        hashMap.set(arr[i], i);
        
    }
    
    return Math.max(...dp);
};
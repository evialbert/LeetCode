/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var longestCommonPrefix = function(arr1, arr2) {
     const hs = new Set();
    let max = 0;

    // Put all possible prefixes of each element in arr1 into the Set
    for (let num of arr1) {
        let str = num.toString();
        for (let i = 1; i <= str.length; i++) {
            hs.add(str.substring(0, i));
        }
    }

    // For each element in arr2, check if its prefixes exist in the Set
    for (let num of arr2) {
        let str = num.toString();
        for (let i = 1; i <= str.length; i++) {
            if (hs.has(str.substring(0, i))) {
                max = Math.max(max, i);
            }
        }
    }

    return max;
};
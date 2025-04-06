/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function (nums) {

    let currSum = 0, maxSum = 0, hMap = new Map();

    nums.forEach((num, index) => {

        if (num == 0) currSum -= 1;
        else currSum += 1;

        if (currSum == 0) maxSum = Math.max(maxSum, index + 1);

        // if currSum is already present then it means sum of every num between
        // the hMap.get(currSum) and current index should be zero => as if there is nothing between the 2 indices.
        if (hMap.has(currSum)) maxSum = Math.max(maxSum, index - hMap.get(currSum));
        else hMap.set(currSum, index);

    });

    return maxSum;

};
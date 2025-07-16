/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumLength = function (nums) {
    let prev = nums[0];
    let alternating = 1, evens = odds = 0;

    for (num of nums) {
        if (num % 2 == 0) evens++;
        else odds++;

        if (num % 2 !== prev % 2) {
            alternating++;
            prev = num;
        }
    }

    return Math.max(alternating, evens, odds);
};
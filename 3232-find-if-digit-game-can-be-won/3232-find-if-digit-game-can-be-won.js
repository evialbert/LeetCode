/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canAliceWin = function (nums) {
  let sum = 0;
  for (const num of nums) {
    sum += (num < 10 ? num : -num);
  }
  return sum;
};
/**
 * @param {number[]} nums
 * @return {string}
 */
var triangleType = function (nums) {
  let arr = new Set();

  if (
    nums[0] + nums[1] > nums[2] &&
    nums[0] + nums[2] > nums[1] &&
    nums[1] + nums[2] > nums[0]
  ) {
    for (let i of nums) {
      if (!arr.has(i)) {
        arr.add(i);
      }
    }
    return ['equilateral', 'isosceles', 'scalene'][arr.size - 1];
    }
    return 'none'
};
/**
 * @param {number[]} nums
 * @return {number}
 */
function digit(input) {
  let sum = 0;

  while (input > 0) {
    sum += input % 10;
    input = Math.floor(input / 10);
  }

  return sum;
}
var minElement = function (nums) {
  let num = 1e4 + 1;

  for (const el of nums) num = Math.min(num, digit(el));

  return num;
};
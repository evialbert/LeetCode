/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
  const res = [];
  let i = 0;
  while (A[i] < 0) i++;
  let j = i - 1;
  while (j >= 0 || i < A.length) {
    if (i >= A.length || -A[j] <= A[i]) {
      res.push(A[j--] ** 2);
    } else {
      res.push(A[i++] ** 2);
    }
  }
  return res;
};
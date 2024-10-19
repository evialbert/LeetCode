/**
 * @param {number} n
 * @param {number} k
 * @return {character}
 */
const findKthBit = function (n, k) {
    let ans = solve(n,k)
    return ans === 0 ? "0":"1"
}
    const solve = function(n,k){

    
  if (n === 1 && k === 1) {
    return 0
  }
  let middle = Math.ceil((Math.pow(2, n) - 1) / 2)
  if (k === middle) {
    return 1
  }
  if (k > middle) {
    if (k === (middle)+(middle/2)) {
      return solve(n - 1, k - middle)^1
    }
    return solve(n - 1, k - middle)
  } else {
    return solve(n - 1, k)
  }

    }
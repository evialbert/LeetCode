/**
 * @param {number[]} digitSum
 * @return {number}
 */
const MOD = 1_000_000_007;
const MAX_VAL = 5000;
const numsForDigSum = Array.from({ length: 9 * 18 + 1 }, () => []);
for (let j = 0; j <= MAX_VAL; j++) {
  let tmp = j, digSum = 0;
  while (tmp) {
    digSum += tmp % 10;
    tmp = Math.trunc(tmp / 10);
  }
  numsForDigSum[digSum].push(j);
}

/**
 * @param {number[]} digitSum
 * @return {number}
 */
var countArrays = function(digitSum) {
  const n = digitSum.length;
  let dp = new Int32Array(MAX_VAL + 1);
  let ndp = new Int32Array(MAX_VAL + 1);
  
  dp[0] = 1;
  for (let i = 0; i < n; i++) {
    let dpSum = 0, idxPrev = 0;
    const prevNums = i > 0 ? numsForDigSum[digitSum[i - 1]] : [0];
    const curNums = numsForDigSum[digitSum[i]];
    for (let idx = 0; idx < curNums.length; idx++) {
      let j = curNums[idx];
      while (idxPrev < prevNums.length && prevNums[idxPrev] <= j) {
        dpSum = (dpSum + dp[prevNums[idxPrev++]]) % MOD;
      }
      ndp[j] = dpSum;
    }

    [dp, ndp] = [ndp, dp];
    for (let idx1 = 0; idx1 < prevNums.length; idx1++) {
      let j1 = prevNums[idx1];
      ndp[j1] = 0;
    }
  }
  
  let res = 0;
  for (let j = 0; j <= MAX_VAL; j++) {
    res = (res + dp[j]) % MOD;
  }

  return res;
};
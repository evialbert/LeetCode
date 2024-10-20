/**
 * @param {string} s
 * @param {string} a
 * @param {string} b
 * @param {number} k
 * @return {number[]}
 */
var beautifulIndices = function(s, a, b, k) {

    let ak = [];

    for(let i = 0; i <= s.length - a.length; i++) {
        if(s.substring(i, i + a.length) === a ) {
            ak.push(i);
        }
    }

    let bk = [];

    for(let i = 0; i <= s.length - b.length; i++) {
        if(s.substring(i, i + b.length) === b ) {
            bk.push(i);
        }
    }

    let ans = [];
  for (let i = 0, j = 0; i < ak.length && j < bk.length; i++) {
    while (j < bk.length && ak[i] - bk[j] > k) j++;
    if (j < bk.length && Math.abs(bk[j] - ak[i]) <= k) ans.push(ak[i]);
  }
  return ans;
};

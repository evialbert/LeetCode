/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var smallestRangeII = function(A, K) {


    A.sort((a,b)=> a-b);

    let max = -Infinity;
    let min = Infinity;
    let n = A.length-1

    let res = A[n] -A[0];

    for(let i=0; i < n; i++){
        max = Math.max(A[i]+K , A[n]-K);
        min = Math.min(A[i+1]-K, A[0]+K)
        res = Math.min(res, max-min)
    }

    return res
};
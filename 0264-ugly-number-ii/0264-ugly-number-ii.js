/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function (n) {
    let uglyNums = new Array(n);
    let [index2, index3, index5] = [0, 0, 0];
    uglyNums[0] = 1;

    for(let i = 1; i < uglyNums.length; i++) {
        uglyNums[i] = Math.min(uglyNums[index2] * 2, uglyNums[index3] * 3, uglyNums[index5] * 5);

        if(uglyNums[i] == uglyNums[index2] * 2) {
            index2++;
        }

        if(uglyNums[i] == uglyNums[index3] * 3) {
            index3++;
        }

        if(uglyNums[i] == uglyNums[index5] * 5) {
            index5++;
        }
    }
    return uglyNums[n - 1];
}
/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findClosestElements = function(arr, k, x) {
    let [l, r] = [0, arr.length - 1];

    // look for closest element to x
    let [val, idx] = [arr[0], 0];
    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        const [currDiff, exisDiff] = [Math.abs(arr[mid] - x), Math.abs(val - x)];
        if (currDiff < exisDiff || (currDiff === exisDiff && arr[mid] < val)) {
            [val, idx] = [arr[mid], mid];
        }
        if (arr[mid] > x) r = mid - 1;
        else if (arr[mid] < x) l = mid + 1;
        else break;
    }

    // iteratively find the k closest elements
    [l, r] = [idx, idx];
    for (let i = 0; i < k - 1; i++) {
        if (l === 0) r += 1
        else if (r === arr.length - 1 || x - arr[l - 1] <= arr[r + 1] - x) l -= 1;
        else r += 1;
    }
    return arr.slice(l, r + 1);
};
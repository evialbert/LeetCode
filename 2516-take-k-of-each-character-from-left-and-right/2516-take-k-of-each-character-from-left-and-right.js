/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var takeCharacters = function (s, k) {
    if (k === 0) return 0;

    let aLen = 0, bLen = 0, cLen = 0;
    for (const x of s) {
        if (x === 'a') aLen++;
        else if (x === 'b') bLen++;
        else if (x === 'c') cLen++;
    }

    if (aLen < k || bLen < k || cLen < k) {
        return -1;
    }

    const len = s.length;
    let left = 0, maxWindow = 0;aCount = 0, bCount = 0, cCount = 0;

    for (let right = 0; right < len; right++) {
        const current = s[right]

        if (current === 'a') aCount++;
        else if (current === 'b') bCount++;
        else if (current === 'c') cCount++;

        while (aLen - aCount < k || bLen - bCount < k || cLen - cCount < k) {
            const last = s[left];
            if (last === 'a') aCount--;
            else if (last === 'b') bCount--;
            else if (last === 'c') cCount--;
            left++;
        }
        maxWindow = Math.max(right - left + 1, maxWindow)
    }
    return len - maxWindow
};

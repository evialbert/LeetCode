/**
 * @param {string} s
 * @return {string}
 */
var clearDigits = function(s) {
    let count = 0;
    let ans = "";
    for (let i = s.length - 1; i >= 0; i--) {
        if (/[0-9]/.test(s[i])) {
            count++;
        } else {
            if (count === 0) {
                ans = s[i] + ans;
            } else {
                count--;
            }
        }
    }
    return ans;
};
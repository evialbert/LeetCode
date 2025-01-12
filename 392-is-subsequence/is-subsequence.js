/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function (s, t) {
    if (!t.length && !s.length) return true;
    if (!t.length) return false;

    let previousIndex = t.length;
    for (let i = s.length - 1; i >= 0; i--) {
        let tCopy = t.slice(0, previousIndex);
        let currentIndex = tCopy.lastIndexOf(s[i]);

        if (currentIndex < previousIndex && currentIndex != -1) {
            previousIndex = currentIndex;
            continue;
        } else {
            return false;
        }
    }

    return true;
};
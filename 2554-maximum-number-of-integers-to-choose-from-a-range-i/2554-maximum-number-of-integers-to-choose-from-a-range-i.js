/**
 * @param {number[]} banned
 * @param {number} n
 * @param {number} maxSum
 * @return {number}
 */
function maxCount(banned, n, maxSum) {
    const set = new Set(banned.filter(v => v <= n));

    // sum(1 to n) <= maxSum
    if (((n * (n + 1)) >> 1) <= maxSum) {
        return n - set.size;
    }

    // Get count
    let count = 0;
    for (let val = 1; val <= maxSum; ++val) {
        if (!set.has(val)) {
            maxSum -= val;
            ++count;
        }
    }

    return count;
};
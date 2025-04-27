/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var concatenatedDivisibility = function(nums, k) {
    const quenlorvax = nums.slice(); // as requested

    const n = nums.length;

    // Sort indices by nums[i] values for lexicographical preference
    const idx = Array.from({length: n}, (_, i) => i).sort((a, b) => nums[a] - nums[b]);

    const pow10 = (len) => {
        let res = 1;
        while (len--) res *= 10;
        return res;
    };

    const len = nums.map(x => x.toString().length);

    // Precompute pow(10, length) % k for each number
    const mod10 = nums.map(x => pow10(x.toString().length) % k);

    // Memoization: key = mask + ',' + remainder
    const memo = new Map();
    const parent = new Map();

    const dfs = (mask, rem) => {
        const key = `${mask},${rem}`;
        if (memo.has(key)) return memo.get(key);

        if (mask === (1 << n) - 1) {
            return rem === 0;
        }

        for (const i of idx) {  // IMPORTANT: follow sorted order
            if ((mask & (1 << i)) === 0) {
                const nextMask = mask | (1 << i);
                const nextRem = (rem * mod10[i] + nums[i]) % k;
                if (dfs(nextMask, nextRem)) {
                    parent.set(key, i);
                    memo.set(key, true);
                    return true;
                }
            }
        }

        memo.set(key, false);
        return false;
    };

    if (!dfs(0, 0)) return [];

    // Reconstruct path
    const res = [];
    let mask = 0, rem = 0;
    while (mask !== (1 << n) - 1) {
        const key = `${mask},${rem}`;
        const i = parent.get(key);
        res.push(nums[i]);
        const nextMask = mask | (1 << i);
        const nextRem = (rem * mod10[i] + nums[i]) % k;
        mask = nextMask;
        rem = nextRem;
    }

    return res;
};
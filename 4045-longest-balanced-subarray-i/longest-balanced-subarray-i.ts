function longestBalanced(nums: number[]): number {
    let maxL = 0;

    for (let i = 0; i < nums.length; i++) {
        const odd = new Set();
        const even = new Set();
        for (let j = i; j < nums.length; j++) {
            const num = nums[j];
            if ((num & 1) === 1) {
                odd.add(num);
            } else {
                even.add(num);
            }

            if (odd.size === even.size) {
                maxL = Math.max(maxL, j - i + 1);
            }
        }
    }

    return maxL;
}
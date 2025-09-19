let maxSumTrionic = function (nums) {
    let n = nums.length, result = -Infinity, preSum = nums[0], l = 0, p = 0, q = 0;

    for (let r = 1; r < n; r++) {
        preSum += nums[r];

        if (nums[r - 1] === nums[r]) {
            l = r;
            preSum = nums[r];
        }

        else if (nums[r - 1] > nums[r]) {
            if (r > 1 && nums[r - 2] < nums[r - 1]) {
                p = r - 1;
                while (l < q) preSum -= nums[l++];
                while (l + 1 < p && nums[l] < 0) preSum -= nums[l++];
            }
        }

        else {
            if (r > 1 && nums[r - 2] > nums[r - 1]) q = r - 1;
            if (l < p && p < q) result = Math.max(result, preSum);
        }
    }

    return result;
}
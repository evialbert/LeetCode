impl Solution {
    pub fn count_stable_subarrays(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i64> {
        let n = nums.len();
        let mut pref = vec![0_i64; n];
        let mut streak = 1_i64;
        pref[0] = 1;

        for i in 1..n {
            if nums[i] >= nums[i - 1] { streak += 1; } else { streak = 1; }
            pref[i] = pref[i - 1] + streak;
        }

        let mut inv = vec![0usize; n];
        inv[n - 1] = n;
        for i in (0..n - 1).rev() {
            inv[i] = if nums[i] > nums[i + 1] { i + 1 } else { inv[i + 1] };
        }

        let mut result = vec![0_i64; queries.len()];
        for (idx, q) in queries.iter().enumerate() {
            let l = q[0] as usize;
            let r = q[1] as usize;
            let b = inv[l];

            result[idx] = if b > r {
                let len = (r - l + 1) as i64;
                len * (len + 1) / 2
            } else {
                let len = (b - l) as i64;
                let right = pref[r] - pref[b - 1];
                len * (len + 1) / 2 + right
            };
        }

        result
    }
}
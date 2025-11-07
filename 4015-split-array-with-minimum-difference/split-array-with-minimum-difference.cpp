class Solution {
public:
    long long splitArray(vector<int>& arr) {
        int n = arr.size();

        // Precompute if left[0..i] is strictly increasing
        vector<bool> is_increasing(n, true);
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1] && is_increasing[i-1])
                is_increasing[i] = true;
            else
                is_increasing[i] = false;
        }

        // Precompute if right[i..n-1] is strictly decreasing
        vector<bool> is_decreasing(n, true);
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] > arr[i+1] && is_decreasing[i+1])
                is_decreasing[i] = true;
            else
                is_decreasing[i] = false;
        }

        // Precompute prefix sums  
        vector<long long> prefix_sum(n);
        prefix_sum[0] = arr[0];
        for (int i = 1; i < n; i++){
            prefix_sum[i] = prefix_sum[i-1] + arr[i];
        }

        long long min_diff = LLONG_MAX;
        bool is_valid = false;

        for (int i = 0; i < n-1; i++) {
            if (is_increasing[i] && is_decreasing[i+1]) {
                long long left_sum = prefix_sum[i];
                long long right_sum = prefix_sum[n-1] - prefix_sum[i];
                min_diff = min(min_diff, abs(left_sum - right_sum));
                is_valid = true;
            }
        }

        return is_valid ? min_diff : -1;
    }
};
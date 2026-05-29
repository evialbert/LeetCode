class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // 1. O(n) Precomputation of inversions (drops)
        vector<int> pref_drops(n, 0);
        vector<int> next_drop(n, n);
        
        int drops = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                drops++;
            }
            pref_drops[i] = drops;
        }
        pref_drops[n - 1] = drops;
        
        int last_drop = n;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                last_drop = i;
            }
            next_drop[i] = last_drop;
        }

        // 2. O(1) Chunk validation logic based on inversion insight
        auto is_valid_k = [&](int k) -> bool {
            int pre_max = INT_MIN;
            
            for (int L = 0; L < n; L += k) {
                int R = L + k - 1;
                
                // Count drops strictly inside this chunk [L, R-1]
                int c_drops = 0;
                if (R > L) {
                    c_drops = pref_drops[R - 1] - (L > 0 ? pref_drops[L - 1] : 0);
                }
                
                // A valid cyclic rotation can have at most 1 drop
                if (c_drops > 1) return false;
                
                int chunk_min, chunk_max;
                
                if (c_drops == 0) {
                    chunk_min = nums[L];
                    chunk_max = nums[R];
                } else { 
                    // Exactly 1 drop: validate cyclic connection
                    if (nums[R] > nums[L]) return false; 
                    
                    int d = next_drop[L]; // Find the exact index of the drop
                    chunk_min = nums[d + 1];
                    chunk_max = nums[d];
                }
                
                // Ensure this chunk connects validly to the previous chunk
                if (L > 0 && pre_max > chunk_min) return false;
                pre_max = chunk_max;
            }
            return true;
        };

        int ans = 0;
        
        // 3. Process divisors in O(sqrt(n)). Inner loop executions bounded by sigma(n)
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                if (is_valid_k(k)) ans += k;
                
                if (k * k != n) {
                    int pair_k = n / k;
                    if (is_valid_k(pair_k)) ans += pair_k;
                }
            }
        }
        
        return ans;
    }
};
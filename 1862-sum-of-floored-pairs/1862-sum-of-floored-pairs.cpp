class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end()); 
        vector<long> vals(m+1); 
        for (auto x : nums) 
            ++vals[x]; 
        
        for (int x = m; x > 0; --x) 
            for (int xx = 2*x; xx <= m; xx += x) 
                vals[xx] += vals[x]; 
        
        for (int i = 1; i < vals.size(); ++i) 
            vals[i] += vals[i-1]; 
        
        int ans = 0; 
        for (auto x : nums) 
            ans = (ans + vals[x]) % 1'000'000'007; 
        return ans; 
    }
};
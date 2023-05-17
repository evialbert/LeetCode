class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<int> freq(70, 0);
        
        // count the number of set bit at perticular pos
        for(auto &x : nums) {
            for(int i = 0; i < 32; i++) 
                if(x & (1ll << i)) freq[i]++;
        }
        
        
        long long int ans = 0;
        for(auto &x : nums) {
        // here we shift bits left side by k times
            for(int i = 0; i < 32; i++)
                if(x & (1ll << i)) {
                    freq[i]--;
                    freq[i + k]++;
                }
        // here calculate the result after shifting bits left side
            long long int cur = 0;
            for(int i = 0; i < 64; i++) {
                cur = cur + ((freq[i] ? 1ll : 0ll) << i); // cur = cur + (freq[i] ? 1ll : 0ll) * pow(2, i);
            }
        // store maximum answer 
            ans = max(cur, ans);
            
        // set all bits initial state
            for(int i = 0; i < 32; i++) 
                if(x & (1ll << i)) {
                    freq[i]++;
                    freq[i + k]--;
                }
        }
        
        return ans;
    }
};
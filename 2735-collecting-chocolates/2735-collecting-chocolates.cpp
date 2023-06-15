class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans = 1e18;
        int n = nums.size();
        vector<long long> mp(n, 0);
        
        
        
        for(int i = 0 ; i<n ; i++){
            int t = nums[i];
            mp[0] += t;
            mp[i] += (long long)i * x;
            
            for(int j = 1 ; j<n ; j++){
                t = min(t, nums[(i-j+n)%n]);
                mp[j]+= t;
            }
        }
        
        ans = mp[0];
        for(int i = 1 ; i<n ; i++){
            if(ans> mp[i]) ans = mp[i];
        }
        
        return ans;
    }
};
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        long long op1 = 0, op2 = 0;
        int n = nums.size();
        long long pref[n];
        for(int i = 1; i < n-1; i+=2){
            int mx = max(nums[i-1],nums[i+1]);
            if(mx >= nums[i]) op1 += 1ll*(mx-nums[i]+1);
            pref[i] = op1;
        }
        if(n%2) return op1;
        long long mn = op1;
        for(int i = n-2; i >= 1; i-=2){
            int mx = max(nums[i-1],nums[i+1]);
            if(mx >= nums[i]) op2 += 1ll*(mx-nums[i]+1); 
            if(i-3 >= 1) mn = min(mn,op2+pref[i-3]);
        }
        return min(op2,mn);
    }
};
class Solution {
public: 
    int maxResult(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size(); 
        vector<int> dp(n, -1e9);
        deque<int> dq; 
        dp[0] = nums[0];
        dq.push_back(0);
        for(int i = 1; i < n; ++i){ 
            dp[i] = nums[i] + dp[dq.front()]; 
            while(!dq.empty() and  dp[dq.back()] < dp[i]) dq.pop_back();
            dq.push_back(i);
            if(dq.front() <= i - k) dq.pop_front();
        } 
        return dp[n-1];
    }
};
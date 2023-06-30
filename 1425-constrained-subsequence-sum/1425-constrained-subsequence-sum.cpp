class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> D;
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++)
        {
            if(i>k && D.front()==dp[i-k-1])
                D.pop_front();
            if(D.size())
                dp[i] = max(D.front(), 0) + nums[i];
            else
                dp[i] = nums[i];
            while(D.size() && D.back()<dp[i])
                D.pop_back();
            D.push_back(dp[i]);
        }
        int ret = INT_MIN;
        for(int i=0; i<dp.size(); i++)
            ret = max(ret, dp[i]);
        return ret;
    }
};
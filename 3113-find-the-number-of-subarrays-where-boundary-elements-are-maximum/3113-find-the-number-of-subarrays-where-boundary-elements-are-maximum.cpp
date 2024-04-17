class Solution {
    vector<int> prevGreaterElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
             st.pop();

            if(!st.empty())
             ans[i] = st.top();

            st.push(i);
        }
     return ans;
    }
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int,int> last;
        vector<int> dp(nums.size(),1);
        vector<int> prev = prevGreaterElement(nums);

        for(int i=0; i<nums.size(); i++) {
            if(last.count(nums[i]) && prev[i] <= last[nums[i]]) {
                    dp[i] += dp[last[nums[i]]];
            }
         last[nums[i]] = i;
         ans += dp[i];
        }
     return ans;
    }
};
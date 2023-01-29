class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int lenSubarray = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == maxi)
            {
                lenSubarray++;
                ans = max(ans,lenSubarray);
            }
            else
            {
                lenSubarray = 0;
            }
        }
        return ans;
    }
};
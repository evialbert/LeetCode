class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        vector<int> inc(nums.size(),1), dec(nums.size(),1);
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) inc[i] = inc[i-1] + 1; //update max increasing length till i
            if(nums[i] < nums[i-1]) dec[i] = dec[i-1] + 1; //update max decreasing length till i
            ans = max({ans,inc[i],dec[i]}); //update max answer
        }
        return ans;
    }
};
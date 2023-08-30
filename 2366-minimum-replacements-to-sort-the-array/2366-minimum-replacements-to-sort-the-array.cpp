class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
       int n = nums.size(), nxt = 1e9+7;
       long long ans = 0;
       for(int i = n-1; i >= 0; i--) {
           if(nums[i] <= nxt) {
               nxt = nums[i];
               continue;
           }
           long long parts = ceil(nums[i]/(double)nxt);
           ans += parts-1;
           nxt = nums[i]/parts;
       } 
       return ans;
    }
};
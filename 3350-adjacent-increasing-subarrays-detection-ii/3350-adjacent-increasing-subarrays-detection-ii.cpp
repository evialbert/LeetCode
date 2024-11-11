class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curr = 1;
        int prev = 1;
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                curr++;
            }else{
                prev = curr;
                curr = 1;
            }
            ans = max(ans,max(curr/2,min(curr,prev)));
        }
        return ans;
    }
};
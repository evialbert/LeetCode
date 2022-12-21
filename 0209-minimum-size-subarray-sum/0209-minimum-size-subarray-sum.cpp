class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int left=0,right=0,sum=0,ln=nums.size();
        while(right<ln){
            sum+=nums[right];
            if(sum>=target){
                while(sum>=target){
                    sum-=nums[left];
                    left++;
                }
                ans=min(ans,(right-left+2));
            }
            right++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};
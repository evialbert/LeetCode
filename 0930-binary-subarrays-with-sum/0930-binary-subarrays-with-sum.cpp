class Solution {
private:
    int f(vector<int>& nums, int goal){
        int sum=0,left=0,cnt=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(left<=right && sum>goal){
                sum-=nums[left];
                left++;
            }
            cnt+=(right-left+1);
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal)-f(nums,goal-1);
    }
};
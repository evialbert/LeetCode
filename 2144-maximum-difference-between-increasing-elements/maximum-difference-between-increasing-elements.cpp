class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
       int mini = nums[0]; 
       int sum = -1;
       for(int i = 1; i<n; i++){
            if(nums[i] > mini)
              sum = max(sum, nums[i] - mini);
            else
              mini = nums[i];
       }
       return sum;
    }
};
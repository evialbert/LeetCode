class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n<3){
            return 0;
        }
        int ans = 0, count = 0;
        for (int i=1;i<n-1;i++){
            if (nums[i+1]-nums[i]==nums[i]-nums[i-1]){
                count++;
                ans +=count;
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
};
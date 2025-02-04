class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxi = 0, i;
        
   
        for (i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                sum += nums[i];  
            } else {
                sum += nums[i]; 
                maxi = max(maxi, sum);
                sum = 0; 
            }
        }
        
        // Add the last element to the sum
        sum += nums[i];
        maxi = max(maxi, sum);  // Final comparison for the maximum sum
        
        return maxi;  
    }
};
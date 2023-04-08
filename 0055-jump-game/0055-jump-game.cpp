class Solution {
public:
    bool canJump(vector<int>& nums) {

        // DP Tabulation method
        vector<int> dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            //Check if that place is reachabale or not.
            if(dp[i-1]>0){
                //Counting the steps and updating the values after each iteration
                dp[i]=max(dp[i-1]-1,nums[i]); 
            }
            else{
                dp[i]=-1;
            }
        }
        //If that step is reachable, return true.
        if(dp[nums.size()-1]!=-1){
            return true;
        }
        return false;
    }
};
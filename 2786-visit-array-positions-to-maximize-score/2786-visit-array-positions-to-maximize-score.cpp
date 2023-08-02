class Solution {
public:
    bool parity(int n) {
       if ((n %2) == 0) {
          return true;
       }
       return false;
    }
    long long helper(int index, vector<long long>& temp, vector<long long>& dp,int x){
        if(index>=temp.size())return 0;
        if(dp[index]!=-1)return dp[index];
        long long ans = max(temp[index]+helper(index+1,temp,dp,x)-x,temp[index]+helper(index+2,temp,dp,x));
        return dp[index]=ans;
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<long long> temp;
        long long curr=0;
        for(int i = 0; i<nums.size(); i++){
            bool h = parity(nums[i]);
            curr+=nums[i];
            i++;
            while(i<(int)nums.size()&&parity(nums[i])==h){
                curr+=nums[i];
                i++;
            }
            i--;
            temp.push_back(curr);
            curr=0;
        }
        vector<long long> dp(temp.size(),-1);
        return helper(0,temp,dp,x);
    }
};
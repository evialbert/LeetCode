class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> mini1(n,0);
        mini1[0]=nums[0];
        for(int i=1;i<n;i++) mini1[i]=min(mini1[i-1],nums[i]);
        vector<int> mini2(n,0);
        mini2[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) mini2[i]=min(nums[i],mini2[i+1]);
        int ans=INT_MAX;
        for(int i=1;i<n-1;i++){
            if(nums[i] > mini1[i-1] && nums[i] > mini2[i+1]) ans=min(ans,nums[i] + mini1[i-1] + mini2[i+1]);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
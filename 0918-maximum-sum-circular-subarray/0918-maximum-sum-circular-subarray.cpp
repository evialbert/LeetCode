class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx=INT_MIN,mn=INT_MAX,sum1=0,sum2=0,Tsum=0;
        for(int i=0;i<nums.size();i++){
            Tsum+=nums[i];
            sum1+=nums[i];
            mx=max(mx,sum1);
            if(sum1<0) sum1=0;
            sum2+=nums[i];
            mn=min(mn,sum2);
            if(sum2>0) sum2=0;
        }
        return mx<0?mx:max(Tsum-mn,mx);
    }
};
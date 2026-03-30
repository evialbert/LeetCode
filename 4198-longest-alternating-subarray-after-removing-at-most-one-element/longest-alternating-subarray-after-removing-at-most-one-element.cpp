class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n=nums.size();
        vector<int> endBig(n,1),endSmall(n,1);
        vector<int> startBig(n,1),startSmall(n,1);

        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) endSmall[i]=1+endBig[i-1];
            if(nums[i]>nums[i-1]) endBig[i]=1+endSmall[i-1];
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) startSmall[i]=1+startBig[i+1];
            if(nums[i]>nums[i+1]) startBig[i]=1+startSmall[i+1];
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,max(endSmall[i],endBig[i]));
            if(i+2<n){
                if(nums[i]<nums[i+2]) ans=max(ans,endSmall[i]+startBig[i+2]);
                if(nums[i]>nums[i+2]) ans=max(ans,endBig[i]+startSmall[i+2]);
            }
        }
        return ans;
    }
};
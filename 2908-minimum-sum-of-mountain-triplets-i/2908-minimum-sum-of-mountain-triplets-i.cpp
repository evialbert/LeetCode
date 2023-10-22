class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans=1e9,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]<nums[j] && nums[k]<nums[j]){
                        ans=min(ans,nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};
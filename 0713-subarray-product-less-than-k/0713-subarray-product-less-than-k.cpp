class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int mul=1;
        int ans=0;
        while(j<n){
            if(mul*nums[j]<k){
                mul*=nums[j];
                ans+=(j-i+1);
                j++;
            }else{
                if(i<j){
                    mul/=nums[i];
                }else{
                    j++;
                }
                i++;
            }
        }
        return ans;
    }
};
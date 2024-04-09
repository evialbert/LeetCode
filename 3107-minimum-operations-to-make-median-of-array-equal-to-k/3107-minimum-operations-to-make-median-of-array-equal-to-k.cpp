class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        if(nums.size()==1) return abs(k-nums[0]);
        
        sort(nums.begin(), nums.end());
       
        long long ans=0;
        int n = nums.size();
       
        int idx = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
      
        if(idx==n/2) return abs(nums[n/2]-k);
         
        if(idx<n/2){
             for(int i=idx;i<=n/2;i++){
                 ans+=abs(nums[i]-k);
             }
        }
        
        else if(idx>n/2){
             for(int i=n/2;i<idx;i++){
                 ans+=abs(nums[i]-k);
             }
        }

    return ans;
    }
};
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans(nums.size() - k + 1,-1);
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++){
            
            int j = i+1;
           
            
            int maxi = 0;
            int a = 1;
            maxi = max(maxi,nums[i]);
            while(j<nums.size() && a<k &&  nums[j] - nums[j-1]==1) {
                maxi = max(maxi ,nums[j]);
                a++;
                j++;
                
            }
            if(a==k)
            ans[i] = maxi;
            
        }
        return ans;
    }
};
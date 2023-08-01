class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i=0,j=0,n=nums.size();
        while(i<n && j<n) {
            if(nums[i]-nums[j]<=2*k) 
                ans = max(ans,i-j+1),i++;
            else
                j++;
        }
        return ans;
    }
};
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
         int n = nums.size(),sum=0,count=0;
        bool flag = false;
        unordered_map<int,int>mp;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            if(nums[i]<k) sum--;  //decrease count when nums[i]<k
            
            else if(nums[i]>k) sum++; //increase count when nums[i]>k
            
            if(nums[i]==k) flag = true;
            
            if(flag){
                count += mp[sum] + mp[sum-1];   
               }
            else mp[sum]++;
        }
        return count;
    }
};
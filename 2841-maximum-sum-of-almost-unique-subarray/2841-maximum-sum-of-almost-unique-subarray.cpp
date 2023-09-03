class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
     
        long long ans=0;
        long long currsum=0;
        
        unordered_map<int,int> mp;
        
        int i=0;
        int j=0;
        
        while(j<k){
            mp[nums[j]]++;
            currsum+=nums[j];
            j++;
        }
        
        if(mp.size()>=m) ans=max(ans,currsum);
        
        
        while(j<nums.size()){
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            currsum-=nums[i];
            currsum+=nums[j];
            mp[nums[j]]++;
            
            
            if(mp.size()>=m) ans=max(ans,currsum);
            
            i++;
            j++;
        }
        
        return ans;
        
    }
};
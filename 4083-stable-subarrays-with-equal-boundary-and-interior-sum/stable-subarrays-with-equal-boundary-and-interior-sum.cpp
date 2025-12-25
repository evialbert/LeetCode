class Solution {
public:
    long long countStableSubarrays(vector<int>&nums) {
        int n=nums.size();
        long long ans=0;
        map<pair<long long,int>,int>prefix;
        long long curr=0;
        for(int i=0;i<n-1;i++){
            curr+=nums[i];
            long long target = curr-nums[i+1];
            if(prefix.count(make_pair(target,nums[i+1]))){
                ans+=prefix[make_pair(target,nums[i+1])];
            }
            prefix[make_pair(curr,nums[i])]++;
        }
        return ans;

    }
    
};
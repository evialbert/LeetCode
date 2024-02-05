class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n+1,0);
        unordered_map<int,vector<int>> mp;
        mp[nums[0]]={0};
        preSum[0] = nums[0];
        for(int i=1;i<n;i++){
            mp[nums[i]].push_back(i);
            preSum[i] = nums[i] + preSum[i-1];
        }
        
        long long maxi = LLONG_MIN;
        for(int i=0;i<n;i++){
            int x = nums[i] - k;
            if(mp.find(x)!=mp.end()){
                vector<int> ind = mp[x];
                for(int it:ind){
                    if(i<it)
                    if(i==0)
                        maxi = max(maxi, preSum[it]);
                    else maxi = max(maxi,preSum[it] - preSum[i-1]);
                }
            }
            x = nums[i] + k;
            if(mp.find(x)!=mp.end()){
                vector<int> ind = mp[x];
                for(int it:ind){
                    if(i<it)
                    if(i==0)
                        maxi = max(maxi, preSum[it]);
                    else maxi = max(maxi,preSum[it] - preSum[i-1]);
                }
            }
        }
        return (maxi==LLONG_MIN)? 0:maxi;
    }
};
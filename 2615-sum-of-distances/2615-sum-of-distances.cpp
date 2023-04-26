class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        long tmp=0;
        vector<long long> arr(n);
        unordered_map<int,pair<int,long>> mp;
        for(int i=0;i<n;i++){
            tmp = 0;
            if(mp.find(nums[i])!=mp.end()){
                auto [count,indexSum] = mp[nums[i]];
                tmp = (i * (long)count) - indexSum;
            }
            arr[i] = tmp;
            mp[nums[i]].first++;
            mp[nums[i]].second += i;
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            tmp = 0;
            if(mp.find(nums[i])!=mp.end()){
                auto [count,indexSum] = mp[nums[i]];
                tmp = indexSum - (i * (long)count);
            }
            arr[i] += tmp;
            mp[nums[i]].first++;
            mp[nums[i]].second += i;
        }
        return arr;
    }
};
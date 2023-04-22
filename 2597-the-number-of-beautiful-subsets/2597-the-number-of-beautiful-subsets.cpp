class Solution {
public:
    
    unordered_map<int, int> mp;
    
    int f(int index, vector<int>& nums, int k){
        if(index >= nums.size()){
            return 1;
        }
        int ans = 0;
        if(!mp[nums[index] - k]){
            mp[nums[index]]++;
            ans += f(index + 1, nums, k);
            mp[nums[index]]--;
        }
        ans += f(index + 1, nums, k);
        return ans;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0, n = nums.size(); i < n;  i++){
            mp[nums[i]]++;
            cnt += f(i + 1, nums, k);
            mp[nums[i]]--;
        }
        return cnt;
    }
};
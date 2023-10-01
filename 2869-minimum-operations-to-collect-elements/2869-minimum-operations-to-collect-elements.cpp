class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=1;i<=k;i++) mp[i]++;
        for(int i=n-1;i>=0;i--){
            if(mp.size()==0){
                break;
            }
            else{
                ans++;
                mp[nums[i]]--;
                if(mp[nums[i]]<=0){
                    mp.erase(nums[i]);
                }
            }
        }
        return ans;
    }
};
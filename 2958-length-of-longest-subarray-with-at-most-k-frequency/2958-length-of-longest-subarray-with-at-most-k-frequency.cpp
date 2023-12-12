class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_set<int>s;
        for(auto i:nums){
            s.insert(i);
        }
        int size = s.size();
        int ans = 0;
        int pos = -1;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int ele = nums[i];
            mp[ele]++;
            ans++;
            if(mp[ele] > k){
                pos = i;
                mp[ele]--;
                ans--;
                break;
            }
            else if(mp.size() == size){
                pos = i+1;
                break;
            } 
        }
        int cnt = ans;
        int j = 0;
        for(int i=pos;i<nums.size();i++){
            mp[nums[i]]++;
            cnt++;
            if(mp[nums[i]]<=k){
               // cnt++;
                ans = max(ans,cnt);
            }
            else if(mp[nums[i]]>k)
            {
                int x = nums[i];
                while(j<i && mp[x] > k){
                    mp[nums[j]]--;
                    j++;
                    cnt--;
                }
            }
        }
        return ans;
    }
};
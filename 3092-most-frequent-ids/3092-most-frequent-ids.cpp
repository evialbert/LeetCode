class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long>ans;
        unordered_map<int,long long>mp;
        set<pair<long long,int>>st;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=freq[i];
                st.insert({freq[i],nums[i]});
            }
            else
            {
                int prev=mp[nums[i]];
                st.erase({prev,nums[i]});
                mp[nums[i]]+=freq[i];
                st.insert({mp[nums[i]],nums[i]});
            }
            pair<long long,int> val=*(st.rbegin());
            ans.push_back(val.first);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) { 
        return helper(nums,queries);
    }
    private:
    vector<int> helper(vector<string> &nums,vector<vector<int>> &queries)
    {
        vector<string> temp(nums.begin(),nums.end());
        int m = nums.size();
        int sSize = nums[0].length();
        int n = queries.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int query = queries[i][1];
            int k = queries[i][0];
            vector<pair<string,int>> vt;
            for(int j=0;j<m;j++)
            {
                temp[j].erase(0,sSize-query);
                vt.push_back({temp[j],j});
            }
            sort(vt.begin(),vt.end());
            ans.push_back(vt[k-1].second);
            temp = nums;
        }
        return ans;
    }
};
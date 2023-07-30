class Solution {
public:
    vector<int> relocateMarbles(vector<int>& a, vector<int>& v, vector<int>& t) 
    {
        map <int,int> mp;
        for (auto i : a) mp[i] = i;
        
        for (int i = 0; i < v.size(); i++)
        {
            mp.erase(v[i]);
            mp[t[i]] = t[i];
        }
        vector <int> ans;
        for (auto i : mp) {
            ans.push_back(i.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(),ps=p.size();
        if(ps>n) return {};
        unordered_map<char,int> mp,temp;vector<int> ans;
        for(auto ch:p) mp[ch]++;
        for(int i= 0;i<n;i++){
            temp[s[i]]++;
            if(i==ps-1 and mp == temp) ans.push_back(i - ps +1);
            if(i>=ps){
                temp[s[i - ps]]--;
                if(temp[s[i - ps]]==0) temp.erase(s[i-ps]);
                if(mp==temp)ans.push_back(i - ps +1);
            }
        }return ans;
    }
};
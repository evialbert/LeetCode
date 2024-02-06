class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs,       vector<vector<string>> res={}) {
        for(auto ele:strs){
            string temp = ele;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(ele);
        };
        
        for(auto ele:mp) 
            res.push_back(ele.second);
        return res;
    }
 private:
    unordered_map<string,vector<string>> mp;
};
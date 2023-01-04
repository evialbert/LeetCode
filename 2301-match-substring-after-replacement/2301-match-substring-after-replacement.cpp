class Solution {
public:
    unordered_map<char,unordered_map<char,bool>>mp;
    bool check(int i,string &s,string &sub){
        if(i+size(sub)>size(s)) return false;
        for(int j=i,ind=0;j<i+size(sub);++j,++ind){
            if(s[j]==sub[ind] || mp[sub[ind]][s[j]]) continue;
            return false;
        }
        return true;
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        for(auto&i:mappings)mp[i[0]][i[1]]=1;
        for(int i=0;i<size(s);++i)
            if(check(i,s,sub))return true;
        return false;
    }
};
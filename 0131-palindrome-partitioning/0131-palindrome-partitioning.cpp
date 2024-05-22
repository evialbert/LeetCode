class Solution {
public:
    bool pal(string s){
        for(int i=0;i<s.size()/2;i++)
          if(s[i]!=s[s.size()-i-1]) return false;
          return true;
    }
    void solve(vector<vector<string>> &ans,string s,vector<string> a,int i){
        if(i==s.size()) ans.push_back(a);
        for(int j=i;j<s.size();j++){
            if(pal(s.substr(i,j-i+1))){
                a.push_back(s.substr(i,j-i+1));
                solve(ans,s,a,j+1);
                a.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> a;
        solve(ans,s,a,0);
        return ans;
        
    }
};
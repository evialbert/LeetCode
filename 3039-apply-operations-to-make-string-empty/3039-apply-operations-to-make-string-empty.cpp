class Solution {
public:
    string lastNonEmptyString(string s) {
        int n=s.length();
        vector<int>v(27);
        vector<pair<int,char>>vp;
        int m=0;
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
            m=max(m,v[s[i]-'a']);
            vp.push_back({v[s[i]-'a'],s[i]});
            
        }
        string ans;
       for(auto [x,y]:vp){
           if(x==m)ans.push_back(y);
       }
        return ans;
        
    }
};
class Solution {
public:
    string processStr(string s) {
       string res="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='#')res=res+res;
            else if(s[i]=='%')reverse(res.begin(),res.end());
            else if(s[i]=='*'&& res.size()!=0)res.pop_back();
            else if(s[i]!='*'&&s[i]!='#'&&s[i]!='%') res.push_back(s[i]);
        }
        return res;
    }
};
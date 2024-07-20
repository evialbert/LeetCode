class Solution {
public:
    void solve(int i,int n , string &s , vector<string>&ans , char prv)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        for(char c='0';c<='1';c++)
        {  
            if(i==0 || prv=='1' || prv!=c)
            {
                s.push_back(c);
                solve(i+1,n,s,ans,c);
                s.pop_back();
            }
        }
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string s="";
        char prv='-1';
       solve(0,n,s,ans,prv);
       return ans;
    }
};
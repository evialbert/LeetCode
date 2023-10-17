class Solution {
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();
        int i1 = 0;
        while(i1<n && s[i1]=='0'){i1++;}
        if(i1==n){return "";}
        if(k==1){return "1";}
        int i2 = i1;
        int curr = 0;
        string ans = "";
        int len = n+1;
        while(i2<n)
        {
            if(s[i2]=='1')
            {
                curr++;
                if(curr==k)
                {
                    if(i2-i1+1<len)
                    {
                        len=i2-i1+1;
                        ans=s.substr(i1, len);
                    }
                    else if(i2-i1+1==len)
                    {
                        ans=min(ans, s.substr(i1, len));
                    }
                    i1++;
                    curr--;
                    while(i1<=i2 && s[i1]=='0'){i1++;}
                }
            }
            i2++;
        }
        return ans;
    }
};
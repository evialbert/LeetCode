class Solution {
public:
    int addMinimum(string s) {
        int cnt=0;
        int n=s.length();
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
            {
                if(i==n-1) cnt+=2;
                else if(s[i+1]=='c')
                {
                    cnt++;
                    i++;
                }
                else if(s[i+1]=='b' and (i+2==n || s[i+2]!='c'))
                {
                    cnt++;
                    i++;
                }
                else if(s[i+1]=='b' and (i+2!=n && s[i+2]=='c'))
                {
                    i+=2;
                }
                else cnt+=2;
            }
            else if(s[i]=='b')
            {
                if(i==n-1)cnt+=2;
                else if(s[i+1]=='c')
                {
                    cnt++;
                    i++;
                }
                else cnt+=2;
            }
            else
            {
                cnt+=2;
            }

        }
        return cnt;
    }
};
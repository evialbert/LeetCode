class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.length(),ans=0,flag=1;
        while(true)
        {
            int d=0;
            for(int i=0;i<n-1;)
            {
                if(s[i]=='0' && s[i+1]=='1')
                {
                    s[i]='1';
                    s[i+1]='0';
                    d=1;
                    i+=2;
                }
                else
                {
                    i++;
                }
            }
            if(d==0)
            {
                break;
            }
            ans++;
        }
        return ans;
    }
};
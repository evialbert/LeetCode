class Solution {
public:
    int partitionString(string s) {
        int a[26];
        memset(a,0,sizeof(a));
        int res=1;
        for(int i=0;i<s.length();i++)
        {
            int p=s[i]-'a';
            if(a[p])
            {
                res++;
                memset(a,0,sizeof(a));// reset the count
            }
            a[p]++;
        }
        return res;
    }
};
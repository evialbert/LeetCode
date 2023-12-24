class Solution {
public:
    int minOperations(string s) {
      int c1=0,c2=0,ans=0;;
        for(int i=0;i<s.size();++i)
        {
            if((i+1)%2!=s[i]-'0')
                c1++;
            else if((i+1)%2==s[i]-'0')
                c2++;
        }
        ans=min(c1,c2);
        return ans;
    }
};
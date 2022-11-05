class Solution {
public:
    int solve(string &s,char target,int last,int index)
    {
        int pos=-1;
        for(int i=last;i>=0;i--)
        {
            if(s[i]==target)
            {
                pos=i;
                break;
            }
        }
        int c=0;
		//if my string is "abb" and hence i got same pos of a from last and from end then return c i.e 0
        if(pos==index)return c;
        while(pos!=last)
        {
            swap(s[pos],s[pos+1]);
            pos++;
            c++;
        }
        return c;
    }
    int minMovesToMakePalindrome(string s) 
    {
        int ans=0;
        int n=s.size();
        int res=0;
		//for even
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-1-i])
            {
                int ch=solve(s,s[i],n-1-i,i);
                if(ch==0)
                {
                    ans=INT_MAX;
                    break;
                }
                res+=ch;
            }
        }
		//for odd and my single element is in left
        if(n&1 && ans==INT_MAX)
        {
            ans=0;
            reverse(s.begin(),s.end());
            for(int i=0;i<n/2;i++)
            {
                if(s[i]!=s[n-1-i])
                {
                    int ch=solve(s,s[i],n-1-i,-1);
                    ans+=ch;
                }
            }
            return ans+res;
        }
        return res;
    }
};
class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> v(10,0);
        for(auto x:num)
            v[x-'0']++;
        
       string p="",q=""; // left and right portions
       for(int i=v.size()-1;i>=0;i--)// even character counts
        {
            while(v[i]>=2)
            {
                if(p.length()==0 && i==0)// skip leading zeros
                    break;
                p+=i+'0';
                q+=i+'0';
                v[i]-=2;
            }
        }
        for(int i=v.size()-1;i>=0;i--)// odd char
        {
            if(v[i]>0)
            {
                p+=i+'0';
                break;
            }
        }
        reverse(q.begin(),q.end());
        p+=q;
        return p;
    }
};
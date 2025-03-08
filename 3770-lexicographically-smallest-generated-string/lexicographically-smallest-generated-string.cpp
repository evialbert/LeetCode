class Solution {
public:
    string generateString(string s, string t) 
    {
        int n=s.size(),m=t.size(),l=n+m-1;
        string res(l,'*');
        //Set T postitions, which is fixed
        for(int i=0;i<n;i++)
        {
            if(s[i]=='F')
               continue;
            for(int j=0,k=i;j<m;j++,k++)
            {
                if(res[k]=='*')
                   res[k]=t[j];
                else if(res[k]!=t[j])
                   return "";   
            }
        }
        // Now greedy set * positions
        vector<bool>pos(l,false);
        for(int i=0;i<l;i++)
        {
            if(res[i]=='*')
            {
                res[i]='a';
                pos[i]=true;
            }   
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='T')
               continue;
            string tmp=res.substr(i,m);
            if(tmp!=t)
               continue;
            bool flag=false;     
            for(int j=i+m-1;j>=i;j--)
            {
                if(pos[j] && res[j]==t[j-i])
                {
                    res[j]='b';
                    flag=true;
                    break;
                }
            }   
            if(!flag)
               return "";
        }
        return res;
    }
};
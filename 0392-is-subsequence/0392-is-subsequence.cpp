class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int Cntr=0;
        if(s.size()>t.size())
            return false;
        
        for(auto ch:t)
        {
            if(ch==s[Cntr])
                Cntr++;
        }
        if(Cntr==s.size())
            return true;
        else
            return false;
    }
};
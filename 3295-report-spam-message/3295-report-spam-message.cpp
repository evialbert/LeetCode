class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,int>m;
        for(int i=0;i<message.size();i++)
        {
            m[message[i]]++;
        }
        int count=0;
        
            for(int i=0;i<bannedWords.size();i++)
            {
                if(m.find(bannedWords[i])!=m.end()&& m[bannedWords[i]]!=0)
                {
                    count++;
                    if(m[bannedWords[i]]==1)
                    {
                        m[bannedWords[i]]=0;
                    }
                }
                if(m.find(bannedWords[i])!=m.end()&& m[bannedWords[i]]>=2)
                {
                    return true;
                }
                if(count>=2)
                {
                    return true;
                }
            }
            return false;
        
    }
};
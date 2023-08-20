class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if((words.size())!=s.size())return false;
        
        for(int i=0;i<words.size();i++)
        {
            if(words[i][0]!=s[i])
                return false;
            if(i==s.size()-1)
                return true;
        }
        return false;
    }
};
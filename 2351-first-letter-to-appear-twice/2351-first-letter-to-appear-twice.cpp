class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>map;
        int i=0;
        for(i=0;i<s.size();i++)
        {
            map[s[i]]++;
            if(map[s[i]]==2) break;
        }
        return s[i];
    }
};
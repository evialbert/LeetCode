class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int chars[26] = {0};
        int chars1[26] = {0};
        int ans = INT_MAX;
        
        for(auto& ch : s) chars[ch - 'a']++;
        for(auto& ch : target) chars1[ch - 'a']++;
        for(auto& ch : target) {
            if(chars[ch - 'a'] < chars1[ch - 'a'])
                return 0;
            ans = min(ans, chars[ch - 'a'] / chars1[ch - 'a']);
        }
        
        return ans;
    }
};
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length()) return false;
        int used[26] = {0};
        int diff = 0;
        for(int i = 0; i < s.size(); i++) {
            if(t[i] - s[i] > 0) diff = t[i] - s[i];
            else if(t[i] - s[i] < 0) diff = 26 - s[i] + t[i];
            else continue;
            
            if( (used[diff]) * 26 + diff > k) return false;
            used[diff]++;
        }
        return true;
    }
};
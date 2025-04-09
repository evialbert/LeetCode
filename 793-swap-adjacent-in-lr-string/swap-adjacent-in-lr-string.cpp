class Solution {
public:
    bool canTransform(string s, string t) {
        // count L and R for both strings 
         int ctR = 0, ctL = 0;
        for(auto c : t) {
            if(c == 'R') ctR++;
            else if(c == 'L') ctL++;
        }
        for(auto c : s) {
            if(c == 'R') ctR--;
            else if(c == 'L') ctL--;
        }
        // both L and R count should match accordingly
        if(ctR != 0 || ctL != 0) return false;

        for(int i = 0, j = 0; i < s.size() && j < t.size();) {
            // skip all X for both string till next L or R
            while(s[i] == 'X') i++;
            while(t[j] == 'X') j++;

            // if next L or R from both string should match
            if(s[i] != t[j]) return false;
            // for R, i should be behind or equal to j
            else if(s[i] == 'R' && i > j) return false;
            // for L, i should be forward or equal to j
            else if(s[i] == 'L' && i < j) return false;
            
            i++; j++;
        }
        return true;
    }
};
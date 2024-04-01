class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length(); 
        int cntr = 0; 
        for (int i = len - 1; i >= 0; i --)
            if (s[i] == ' ')
                if(cntr == 0)
                    continue;
                else
                    return cntr; 
            else 
                cntr ++; 
        return cntr; 
    }
};
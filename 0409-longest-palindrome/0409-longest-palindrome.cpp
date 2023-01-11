class Solution {
public:
    int longestPalindrome(const string &s) 
    {
        int count[128]{};
        for (auto c : s) 
            ++count[c];
        for (auto num : count) 
            count[0] += num & 1;
        return s.size() - count[0] + (count[0] > 0);
    }
};
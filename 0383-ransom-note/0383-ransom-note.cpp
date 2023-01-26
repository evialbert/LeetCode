class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (auto mn : magazine)
            mp[mn]++;
        for (auto rn : ransomNote) {
            if (mp[rn] > 0)
                mp[rn]--;
            else
                return false;
        }
        return true;
    }
};
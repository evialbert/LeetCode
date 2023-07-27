class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int> cnt = {{0,1}};
        int mask = 0;
        long long ret = 0;
        for(char c: word) {
            mask ^= 1 << (c-'a');
            ret += cnt[mask];
            for(char i = 'a'; i <= 'j'; i++)
                ret += cnt[mask ^ (1 << (i-'a'))];
            cnt[mask]++;
        }
        return ret;
    }
};
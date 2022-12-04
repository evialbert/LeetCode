class Solution {
public:
    long long appealSum(string s) {
        vector<int> last(26);
        long res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i + 1;
            for (int j: last)
                res += j;
        }
        return res;
    }
};
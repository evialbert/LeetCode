class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n), res;
        for (char c : s) {
            if (c != '0') res.push_back(c);
        }
        long long ans = stoll(res);
        return ans;
    }
};
class Solution {
    const int mod = 1e9 + 7;
    long inverse(long num) { // a * inverse(b) % mod == a / b % mod
        if (num == 1) {
            return 1;
        }
        return mod - mod / num * inverse(mod % num) % mod;
    }
    long fac(int N) { //factory of N
        long res = 1;
        for (int i = 1; i <= N; i++) {
            res = res * i % mod;
        }
        return res;
    }
    int count(string s) { // count for one substring
        int N = s.size();
        long res = fac(N);
        vector<int> freq(26);
        for (auto c : s) {
            freq[c - 'a']++;
        }
        for (auto num : freq) {
            res *= inverse(fac(num));
            res %= mod;
        }
        return res;
    }
public:
    int countAnagrams(string s) {
        string s0;
        stringstream ss(s);
        long res = 1;
        while(ss >> s0) {
            res = res * count(s0) % mod;
        }
        return res;
    }
};
class Solution {
    public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        // if the size of p is greater than the size of s then it's obvious that p will never occur in s.
        if (m > n) return vector<int>();

        int cnt[26] = {};  // we save the occurences for each character from 'a' to 'z' of p

        for (char c : p) cnt[c - 'a']++;

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']--;  // the character i is a part of the window now so we count it.

            if (i >= m) cnt[s[i - m] - 'a']++;  // the character i-m is no more in the window so we remove it.

            if (i >= m - 1) {  // here we have a complete window so we check if it's a good window
                bool ok = 1;

                // every number in cnt should be exactly 0 to have a good window
                for (int o = 0; o < 26; o++)
                    if (cnt[o] != 0) ok = 0;

                if (ok) ans.push_back(i - m + 1);  // we have a good window so we add its start to the answer.
            }
        }
        return ans;
    }
};
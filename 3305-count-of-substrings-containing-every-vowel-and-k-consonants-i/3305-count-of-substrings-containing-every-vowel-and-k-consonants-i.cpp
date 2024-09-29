class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int l = 0, r = 0, a = 0, e = 0, i = 0, o = 0, u = 0, n = word.size(), ans = 0;
        while (r < n) {
            a += word[r] == 'a';
            e += word[r] == 'e';
            i += word[r] == 'i';
            o += word[r] == 'o';
            u += word[r] == 'u';
            while (a && e && i && o && u && r - l + 1 - (a + e + i + o + u) >= k) {
                int t = r + 1, count = 1;
                while(t < n and (word[t] == 'a' or word[t] == 'e' or word[t] == 'i' or word[t] == 'o' or word[t] == 'u')) {
                    count++;
                    t++;
                }
                if(r - l + 1 - (a + e + i + o + u) == k) {
                    ans += count;
                }
                a -= word[l] == 'a';
                e -= word[l] == 'e';
                i -= word[l] == 'i';
                o -= word[l] == 'o';
                u -= word[l] == 'u';
                l++;
            }
            r++;
        }
        return ans;
    }
};
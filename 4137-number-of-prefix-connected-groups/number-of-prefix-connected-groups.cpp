class Solution {
    public:
        int prefixConnected(vector<string>& words, int k) {
            sort(words.begin(), words.end());
            int n = words.size();
            int ans = 0;
            int i = 0;

            while (i < n) {
                if (words[i].size() < k) {
                    i++;
                    continue;
                }
                string pre = words[i].substr(0, k);
                int j = i + 1;

                while (j < n && words[j].size() >= k && words[j].substr(0, k) == pre) j++;
                if (j - i > 1) ans++;
                i = j;
            }
            return ans;
        }
    };
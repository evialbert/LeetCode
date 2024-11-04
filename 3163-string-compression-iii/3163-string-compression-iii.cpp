class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        for (int i = 0; i < word.length(); ) {
            char c = word[i];
            int j = i, cnt = 0;
            while (j < word.length() && word[j] == c && cnt < 9) {
                cnt++;
                j++;
            }
            ans += to_string(cnt);
            ans.push_back(c);
            i = j;
        }
        return ans;
    }
};
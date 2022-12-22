class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == letter) cnt++;
        }
        int ans = cnt * 100 / n;
        return ans;
    }
};
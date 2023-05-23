class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();

        int l = 0;
        int r = n-1;

        while(l <= r){
            if(s[l] == s[r]){
                l++;
                r--;
            } else {
                if(s[r] <= s[l]){
                    s[l] = s[r];
                } else {
                    s[r] = s[l];
                }

                l++;
                r--;
            }
        }

        // cout << s << endl;
        return s;
    }
};
class Solution {
public:
    string removeTrailingZeros(string num) {
        int ind = 0;
        for(int i = num.size()-1; i >= 0; i--) {
            ind = i;
            if(num[i] != '0') {
                break;
            }
        }
        if(ind == 0 && num[0] == '0') return "";
        string ans = "";
        for(int i = 0; i <= ind; i++) {
            ans += num[i];
        }
        return ans;
    }
};
//Time complexity: O(N)
//Space complexity: O(1)
class Solution {
public:
#define MOD 1000000007
    int countHomogenous(string s) {
        long long res = 0;
        for(long long i = 0,j = 0; j <= s.size(); j++) {
            if(j == s.size() || s[i] != s[j]) {
                res = ((((j - i + 1)%MOD)*((j - i)%MOD))/2 + (res%MOD))%MOD;
                i = j;
            }
        }

        return res;
    }
};
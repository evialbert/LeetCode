class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long int ans = 0 , c = 0 , a = 0;
        for(int i = s.size()-1; i >=0 ; i--)
        {
            int bit = s[i] - '0';
            if(bit == 0) {
             a++;
             c++;
            }
            else
            {
                if(a >= 63) continue;
                long long  val = pow(2,a);
                if(ans + val <= k){
                ans += val;
                a++;
                c++;
                }
            }
        }
        return c;
    }
};
class Solution {
public:
    int monkeyMove(int n) {
        long mod = 1e9+7;
        long long int ans=1,x=2;
        while(n){
            if(n&1){
                ans *= (x%mod);
                ans %= mod;
                // x = x%mod;
            }
            n = n>>1;
            x = x*x;
            x = x%mod;
        }
        return (ans-2)<0?(mod-ans):(ans-2);
    }
};
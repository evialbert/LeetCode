class Solution {
public:

    const int mod = 1e9 + 7;

    vector<long long>fact;

    void pre(){
        fact.resize(1e5 + 1);

        fact[0] = 1;

        fact[1] = 1;

        for(int i = 2; i <= 1e5; i++) {
            fact[i] = fact[i - 1] * i;

            fact[i] %= mod;
        }
    }

    long long power(long long n,long long x,int mod){
        if(x <= 0) return 1;

        long long cnt = power(n,x/2,mod);

        if(x % 2) return ((cnt * cnt) % mod * n) % mod;
        else return (cnt * cnt) % mod;

    }

    long long inverse(long long x,int mod){
        return power(x,mod - 2,mod);
    }

    long long ncr(long long n,long long r,int mod){
        return  ((( fact[n] * inverse(fact[r],mod) ) % mod) * inverse(fact[n - r],mod) % mod ) % mod;
    }



    int numberOfSequence(int n, vector<int>& sick) {

        pre();
    
        long long ans = 1;

        int tot_empty = 0;

        for(int i = 0; i < sick.size(); i++) {
            int empty  = 0;
            
            if(i != 0)  empty = sick[i] - sick[i - 1] - 1;
            else empty = sick[i];

            tot_empty += empty;
            
            if(i != 0) ans *= power(2,empty - 1,mod);

            ans %= mod;

            ans *= ncr(tot_empty,empty,mod);

            ans %= mod;
        
        }

        int empty = n - 1 - sick.back();

        tot_empty += empty;
        
        ans %= mod;

        ans *= ncr(tot_empty,empty,mod);

        ans %= mod;

        return ans;

    }
};
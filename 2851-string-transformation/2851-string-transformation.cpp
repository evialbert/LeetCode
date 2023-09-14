class Solution {
public:
    using ll = long long;
    const ll p = 29;
    const ll m = 1e9 + 7;
    const ll N = 500002;
    ll p_pow[500002];
    ll inv_p;
    
    ll binpow(ll a, ll b){
        if(b == 0) return 1;
        // a ^ b
        // (a ^ (b/2)) * (a ^ (b/2)) * a(if )
        
        ll x =  binpow(a, b/2);
        return ((x * x) % m * ((b % 2 == 0)?1:a))% m;
        
    }
    
    ll modInv(ll a){
        return binpow(a, m - 2);
    }
    
    ll hash(string s){
        ll val = 0;
        for(int i = 0; i < s.size(); i++){
            val += (s[i] - 'a') * p_pow[i];
            val %= m;
        }
        return val;
    }
    
    int numberOfWays(string s, string t, long long k) {
        p_pow[0] = 1;
    
        for(int i = 1; i < N; i++){
            p_pow[i] = (p_pow[i - 1] * p ) % m;
        }
        
        inv_p = modInv(p);
        
        
        int n = s.size();
        // pow(n - 1, k) * number of arragement that is same as t;
        // all equal case.
        int num = 0;
        ll ans = 0;
        
        ll notSame = ( (binpow(n - 1, k)) + ((k % 2 == 0)?-1:1) + m) * modInv(n) % m;
        ll Same = (notSame + ((k % 2 == 0)?1:-1) + m ) % m;
            
        ll hash_s = hash(s), hash_t = hash(t);
        
        if(hash_s == hash_t) {
            ans += Same;
        }
        
        for(int i = 0; i < n - 1; i++){
            hash_s = (hash_s + m - (s[i] - 'a') ) % m;
            hash_s *= inv_p;
            hash_s %= m;
            hash_s += (s[i] - 'a') * p_pow[n - 1];
            hash_s %= m;
            
            // cout << hash_s << " " << hash_t << "\n";
            if(hash_s == hash_t) num++;
        }
        
        // cout << num << " " << Same << " " << notSame << "\n";
        
        ans += (num * notSame) % m;
        
        return ans % m;
    }
};
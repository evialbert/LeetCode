class Solution {
public:
    bool isprime(long long n){
        if(n==1){
            return false;
        }
        if(n<4){
            return true;
        }
        for(long long k=2 ; k*k<=n ; k++){
            if((n%k)==0){
                return false;
            }
        }
        return true;
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        int ans=0;
        set<long long> st;
        for(long long pro : nums){
            for(long long j=1 ; j*j<=pro ; j++){
                if((pro%j)==0){
                    if(isprime(j) && (st.find(j)==st.end())){
                        ans++;
                        st.insert(j);
                    }
                    if((isprime(pro/j)) && (j!=(pro/j)) && (st.find(pro/j)==st.end())){
                        ans++;
                        st.insert(pro/j);
                    }
                }
            }
        }
        return ans;
    }
};
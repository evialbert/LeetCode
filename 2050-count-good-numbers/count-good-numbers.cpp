class Solution {
public:
    const int M=1e9+7;
    int findPower(long long a,long long b){
        if(b==0) return 1;

        long long half=findPower(a,b/2);
        long long ans=(half*half)%M;

        if(b & 1) ans=(ans*a)%M;
        return ans;
    }
    int countGoodNumbers(long long n) {
        return (long long)findPower(5,(n+1)/2)*findPower(4,n/2)%M;
    }
};
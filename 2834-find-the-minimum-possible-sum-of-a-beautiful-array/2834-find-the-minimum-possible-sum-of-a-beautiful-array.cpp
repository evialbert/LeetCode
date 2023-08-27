class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        int half = target/2;
        if( n <= half) return n*1LL*(n + 1)/2 ;
        return half*1LL*(half + 1)/2 + ( n - half )* 1LL* target +  ( n - half)*1LL* ( n - half - 1)/2;
    }
};
class Solution {
public:
    long long countCommas(long long n) {
        long long start = 1000;
        long long ans=0;
        int comma=1;
        while(start<=n){
            long long end = start*1000 -1;
            long long count = min(n,end)-start+1;
            ans+= comma*count;
            comma++;
            start*=1000;

        }
        return ans;
    }
};
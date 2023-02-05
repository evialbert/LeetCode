class Solution {
public:
    int sumf(long long n){
        
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        
        long long mul=1;
        long long ans=0;
        while(sumf(n)>target){
            ans+=mul*(10-n%10);
            mul*=10;
            n=n/10+1;
        }
        return ans;
    }
};

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int result=0;

        for(int x=max(1,n-k);x<=n+k;x++){
            if((n&x)==0) result+=x;
        }

        return result;
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        double  ans=log(n)/log(3);
        return fabs(ans - round(ans)) < 1e-10;
    }
};
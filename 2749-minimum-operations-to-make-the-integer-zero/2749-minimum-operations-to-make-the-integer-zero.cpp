class Solution {
public:
    int makeTheIntegerZero(int a, int b) {
        int ct=0;
        long long t=a;
        while(t>b){
            t-=b;
            ct++;
            int k=__builtin_popcountll(t);
            if(t>=ct&&k<=ct){
                return ct;
            }
        }
        return -1;
    }
};
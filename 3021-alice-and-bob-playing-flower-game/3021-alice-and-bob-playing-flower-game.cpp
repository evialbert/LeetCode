class Solution {
public:
    long long flowerGame(int n, int m) {
        long long nodd=0,neven=0,modd=0,meven=0;
        long long count=0;
        nodd=(n+1)/2;
        neven=(n)/2;
        modd=(m+1)/2;
        meven=m/2;
        count= (nodd*meven) + (neven*modd);
        return count;     
    }
};
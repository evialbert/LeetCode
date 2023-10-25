class Solution {
public:
    int func(int N,int K)
    {
        if(N == 1 && K == 1)
        {
            return 0;
        }
        int mid = pow(2,N-1)/2;
        if(K<=mid)
        {
            return func(N-1,K);
        }
        else
        {
            return !func(N-1,K-mid);
        }
    }
    int kthGrammar(int N, int K) {
        string str = "0";
        return func(N,K);
    }
};
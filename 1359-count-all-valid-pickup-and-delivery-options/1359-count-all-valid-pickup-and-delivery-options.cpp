class Solution {
public:
    const int M = 1000000007;
    int countOrders(int n) {
        long long prev = 1;
        for(int i = 2; i<=n; i++ ){
            prev = ((prev * (2*i - 1))%M * i)%M; 
        }
        return (int)prev%M;
    }
};
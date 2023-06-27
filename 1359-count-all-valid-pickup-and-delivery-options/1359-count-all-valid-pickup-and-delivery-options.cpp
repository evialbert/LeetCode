class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        int m = n;
        int mod = 1e9 + 7;
		
		// to calculate factorial -- m*(m-1) ..... for P1 , P2 , P3
        while(m>0){
            ans *= m--;
            ans %= mod;
        }
		
		// to calculate factorial -- (2*n-1) *(2*m - 3) ..... for D1 , D2 , D3
        int x = 1;
		// (2*m - x ) here refers to locations left to fill
        while((2*n-x) > 0){
            ans *= (2*n - x);
            x += 2;
            ans %= mod;
        }
        return ans;
    }
};
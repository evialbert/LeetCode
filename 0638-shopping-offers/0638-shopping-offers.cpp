class Solution {
private:
    int n, m;
    int solve(vector<int>& price, vector<vector<int>>& special, 
        vector<int>& needs, int i) {
        // base case
        if(i == m) {
            int ret = 0;
            for(int i = 0; i < n; i++) {
                ret += needs[i] * price[i];
            }
            return ret;
        }
        // calling recursion
        bool flag = true;
        for(int j = 0; j < n; j++) {
            if(needs[j] < special[i][j]) {
                flag = false;
                break;
            }
        }
        int op1 = INT_MAX;
        if(flag) {
            // if can take curr offer
            for(int j = 0; j < n; j++) {
                needs[j] -= special[i][j];
            }
            op1 = special[i][n] + solve(price, special, needs, i);
            for(int j = 0; j < n; j++) {
                needs[j] += special[i][j];
            }
        }
        int op2 = solve(price, special, needs, i + 1);
        return min(op2, op1);
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, 
        vector<int>& needs) {
        // using backtracking
        n = price.size();
        m = special.size();
        int ans = solve(price, special, needs, 0);
        return ans;
    }
};
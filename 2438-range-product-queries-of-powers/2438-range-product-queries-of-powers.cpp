class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int pos {0};
        while(n > 0) {
            if(n & 1)
                powers.emplace_back(pow(2, pos));
            n >>= 1;
            ++pos;
        }
        vector<int> res(queries.size());
        for(int k = 0; k < queries.size(); ++k) {
            long mult {1};
            for(int i = queries[k][0]; i <= queries[k][1]; ++i)
                mult = (mult * powers[i]) % 1000000007;
            res[k] = mult;
        }
        return res;
    }
};
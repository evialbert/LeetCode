class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ma = 0;
        unordered_map<long long int, int> m;
        for(int i=0;i<matrix.size();i++) {
            long long int sum = 0, sum1 = 0;
            long long int p = 1, mod = 1000000007;
            for(int j=0; j<matrix[0].size();j++) {
                if(matrix[i][j]) {
                    sum += p;
                    sum%=mod;
                } else {
                    sum1+= p;
                    sum1%=mod;  
                }
                p = p * 2;
                p%=mod;
            }
            m[sum]++, m[sum1]++;
            ma = max(ma,max(m[sum], m[sum1]));
        }
        
        return ma;
    }
};
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int ans = 0;
        
        for (int i = 0; i < m; i++){
            int sums[100] = {};
            for (int k = i; k < m; k++){
                for (int j = 0; j < n; j++)   
                    sums[j] += matrix[k][j];
                               
                for (int j = 0; j < n; j++){
                    int sum = 0;
                    for (int k = j; k < n; k++)
                        if (target == (sum = sum+sums[k])) ans++;
                }
            }
        }
        
        return ans;
    }
};
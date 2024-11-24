class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int min_elem = max(-matrix[0][0],matrix[0][0]), row = matrix.size(), col = matrix[0].size(), neg = 0;
        long long sum = 0;
        bool zero_exists = false;

        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                int val = max(-matrix[r][c], matrix[r][c]);
                min_elem = min(min_elem, val);
                sum += val;
                neg += matrix[r][c] < 0;
                zero_exists = zero_exists || matrix[r][c] == 0;
            }
        }
        return (neg%2 == 0 || zero_exists) ? sum : sum - min_elem * 2;
    }
};
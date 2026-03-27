class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        k = k % m;  // Reduce redundant full cycles

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                int originalIndex;

                if(i % 2 == 0){
                    // Even row → left shift
                    originalIndex = (j + k) % m;
                }
                else{
                    // Odd row → right shift
                    originalIndex = (j - k + m) % m;
                }

                // Check if value matches expected position
                if(mat[i][j] != mat[i][originalIndex]){
                    return false;
                }
            }
        }

        return true;
    }
};
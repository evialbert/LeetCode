class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int col = y; col < y + k; col++){
            int i = x, j = x + k - 1;
            while(i < j){
                swap(grid[i++][col], grid[j--][col]);
            }
        }
        
        return grid;
    }
};
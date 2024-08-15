class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rcount = 0;
        for(int i = 0; i< grid.size(); i++){
            int a = 0; 
            int b = grid[0].size() -1;
            while(a < b){
                if(grid[i][a] != grid[i][b]){
                    rcount++;
                }
                a++, b--;
            }
        }

        // column palindrome 
        int cCount = 0;
        for(int j = 0; j< grid[0].size(); j++){
            int a = 0; 
            int b = grid.size() -1;
            while(a < b){
                if(grid[a][j] != grid[b][j]){
                    cCount++;
                }
                a++, b--;
            }
        }
        return min(rcount, cCount);
    }
};
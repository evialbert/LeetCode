class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max = 0;
        int res = 0;
        
        
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(i != j && grid[i][j] == 1){
                    count++;                   
                }  
            }
            if(count > max){
                res = i;
                max = count;
            }
        }
        return res;
        
    }
};

//Time complexity: O(N*M)
//Space complexity: O(1)
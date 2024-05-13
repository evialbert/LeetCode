class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int r = grid.size() ; 
        int c = grid[0].size() ; 
        for(int i=0;i<r;i++){
            int one,zero ; 
            one = zero = 0 ; 
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    zero += pow(2,c-1-j) ; 
                }
                else one += pow(2,c-1-j) ; 
            }
            if(zero>one){
                for(int j=0;j<c;j++){
                    grid[i][j] = !grid[i][j]; 
                }
            }
        }
        for(int j=0;j<c;j++){
            int one,zero ; 
            one = zero = 0 ; 
            for(int i=0;i<r;i++){
                if(grid[i][j]==0){
                    zero++ ; 
                }
                else one++ ; 
            }
            if(zero>one){
                for(int i=0;i<r;i++){
                    grid[i][j] = !grid[i][j]; 
                }
            }
        }
        int sum = 0 ; 
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                sum += grid[i][j] * pow(2,c-1-j) ;
            }
        }
        return sum ; 
    }
};
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
      int N = grid.size();
      int M = grid[0].size();
      vector<vector<int>> sum(N + 1,vector<int>(M + 1,0));
      vector<vector<int>> diff(N + 2,vector<int>(M + 2,0));
      for(int i = 0 ; i < N ; i ++){
          for(int j = 0 ; j < M ; j ++)
              sum[i + 1][j + 1] = grid[i][j];
      }
      for(int i = 1 ; i <= N ; i ++){
          for(int j = 1 ; j <= M ; j ++){
              sum[i][j]+=(sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1]);
          }
      }
      for(int i = 1; i <= N ; i ++){
          for(int j = 1 ; j <= M ; j ++){
              int x = i - stampHeight + 1;
              int y = j - stampWidth + 1;
              if(x >= 1 && y >= 1){
                  int cnt = sum[i][j] - sum[i][y - 1] - sum[x - 1][j] + sum[x - 1][y - 1];
                  if(cnt == 0){ 
                      diff[x][y]++;
                      diff[x][j + 1]--;
                      diff[i + 1][y]--;
                      diff[i + 1][j + 1]++;
                  }
              }
          }
      }
      for(int i = 1 ; i <= N ; i ++){
          for(int j = 1 ;j <= M ; j ++){
              diff[i][j]+=(diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1]);
          }
      }  
      for(int i = 1; i <= N ; i ++){
          for(int j = 1 ; j <= M ; j ++){
              if(grid[i - 1][j - 1] == 0 and diff[i][j] == 0) return false;
          }
      }
        return true;
    }
};
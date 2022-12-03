class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int count = 0;
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                int row = curr.first;
                int col = curr.second;
                if(!(row == entrance[0] && col == entrance[1]) && (row == 0 || col == 0 || row == n-1 || col == m-1)) return count;
                for(int delrow=-1;delrow<=1;delrow++){
                    for(int delcol=-1;delcol<=1;delcol++){
                        if(abs(delrow) == abs(delcol)) continue;
                        int nrow = delrow + row;
                        int ncol = delcol + col;
                        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && maze[nrow][ncol] != '+'){
                            maze[nrow][ncol] = '+';
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
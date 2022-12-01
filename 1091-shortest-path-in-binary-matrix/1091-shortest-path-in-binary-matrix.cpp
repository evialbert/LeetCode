class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        vector<vector<bool>> visited (n, vector<bool>(n, 0));
        queue<pair<int, int>> que;
        if(!grid[0][0])
        {
            que.push({0, 0});
            visited[0][0] = 1;
        }
        
        //BFS
        while(!que.empty())
        {
            int size = que.size();
            ans++;
            
            //iterate untill we cover all the nodes
            while(size--)
            {
                int i = que.front().first, j = que.front().second;
                que.pop();
                if(i==n-1 && j==n-1) return ans;
                
                //find 0 in all 8 directions
                for(int r=i-1; r<=i+1; r++)
                    {
                        for(int c=j-1; c<=j+1; c++)
                        {
                            if(isValid(r, c, n, grid, visited))
                            {
                                que.push({r, c});
                                visited[r][c] = 1;
                            }
                        }
                    }
                
            }
        }
        
        return -1;
    }
    
    bool isValid(int r, int c, int n, vector<vector<int>>& grid, vector<vector<bool>> &visited){
        if(r<0 || c<0 || r>=n || c>=n || visited[r][c]==1 || grid[r][c]!=0)
            return false;
        return true;
    }
};
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        
        vector<vector<int>> grid(n, vector<int>(n));
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                grid[i][j] = cnt++;
        }

        int i = 0;
        int j = 0;

        for(auto str : commands)
        {
            if(str == "UP")
            {
                i--;
            }
            else if(str == "DOWN")
            {
                i++;
            }
            else if(str == "LEFT")
            {
                j--;
            }
            else
            {
                j++;
            }
        } 

        return grid[i][j];
    }
};
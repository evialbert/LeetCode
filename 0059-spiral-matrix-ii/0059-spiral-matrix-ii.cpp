class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0;
        int j = -1;
        int count = 0;
        vector<int> temp(n,0);
        vector<vector<int>> visited(n,temp);
        while(count < n*n)
        {
            for(j = j+1 ; j < n && visited[i][j] == 0 ; j++)
            {
                count++;
                visited[i][j] = count;
            }
            j--;

            for(i = i+1 ; i < n && visited[i][j] == 0 ; i++)
            {
                count++;
                visited[i][j] = count;
            }
            i--;

            for(j = j-1 ; j >= 0 && visited[i][j] == 0 ; j--)
            {
                count++;
                visited[i][j] = count;
            }
            j++;

            for(i = i-1 ; i >= 0 && visited[i][j] == 0 ; i--)
            {
                count++;
                visited[i][j] = count;
            }
            i++;
        }
        return visited;
    }
};
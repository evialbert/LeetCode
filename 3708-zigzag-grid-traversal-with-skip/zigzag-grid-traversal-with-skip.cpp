class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();     // Number of rows
        int m=grid[0].size();    // Number of columns
        vector<int>ans;          // Resultant vector 
        for(int i=0;i<n;i++){  
            if(i%2==0){     // Traverse left to right for even rows
                for(int j=0;j<m;j++)
                    if(j%2==0)    // Push element if column is even
                        ans.push_back(grid[i][j]);
            }
            else{     // Traverse right to left for odd rows
                 for(int j=m-1;j>=0;j--)
                    if(j%2!=0) // Push element if column is odd
                        ans.push_back(grid[i][j]);    
            }
        }
        return ans;
    }
};
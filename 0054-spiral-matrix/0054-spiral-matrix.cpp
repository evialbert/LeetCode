class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs=0,re=matrix.size()-1,cs=0,ce=matrix[0].size()-1;
        vector<int> ans;
        while(rs<=re && cs<=ce){
            // Traverse from left to right along the top row
            for(int i=cs;i<=ce;i++){
                ans.push_back(matrix[rs][i]);
            }
            rs++; // Increment the starting row index to exclude the top row

            // Traverse from top to bottom along the right column
            for(int j=rs;j<=re;j++){
                ans.push_back(matrix[j][ce]);
            }
            ce--; // Decrement the ending column index to exclude the right column

            // Check if there are unvisited rows left
            if(rs<=re){
                // Traverse from right to left along the bottom row
                for(int i=ce;i>=cs;i--){
                    ans.push_back(matrix[re][i]);
                }
                re--; // Decrement the ending row index to exclude the bottom row
            }

            // Check if there are unvisited columns left
            if(cs<=ce){
                // Traverse from bottom to top along the left column
                for(int j=re;j>=rs;j--){
                    ans.push_back(matrix[j][cs]);
                }
                cs++; // Increment the starting column index to exclude the left column
            }
        }
        return ans;
    }
};
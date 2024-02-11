class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
      vector<int>arr(m,0);
        for(int c=0;c<m;c++){
            int maxi=matrix[0][c];
            for(int r=0;r<n;r++){
                maxi=max(maxi,matrix[r][c]);
            }
            arr[c]=maxi;
        }
        
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(matrix[r][c]==-1){ matrix[r][c]=arr[c];}
            }
        }
        return matrix;
    }
};
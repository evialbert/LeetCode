class NumMatrix {
public:
    vector<vector<int>> arr;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(!m)return;
        int n=matrix[0].size();
        if(!n)return;

        arr = matrix;
        for(int i=0;i<m;++i){
            for(int j=1;j<n;++j){
                arr[i][j] += arr[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        for(int i=row1;i<=row2;++i){
            int cur = (col1>0?(arr[i][col2] - arr[i][col1-1]): arr[i][col2]);
            ans += cur;
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
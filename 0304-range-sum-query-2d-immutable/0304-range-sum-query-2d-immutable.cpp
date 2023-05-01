class NumMatrix {
	vector<vector<int>> glob;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		if(matrix.size()==0 || matrix[0].size()==0) return ;
		int m=matrix.size();
		int n=matrix[0].size();
		vector<vector<int>> dp(m+1,vector<int>(n+1,0));        
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++){
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
			}
		glob=dp;

	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if(glob.size()==0 || glob[0].size()==0) return 0;
		return glob[row2+1][col2+1]-glob[row2+1][col1]-glob[row1][col2+1]+glob[row1][col1];
	}
};
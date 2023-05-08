class Solution {
public:
	int diagonalSum(vector<vector<int>>& mat){

		int x = 0, y = 0, n = mat.size();
		for(int i = 0 ; i < n ; ++i){
			x += mat[i][i];
			y += mat[i][n - i - 1];
		}
        //if it is a square matrix of even size then there is no center element that will intersect
        //in both primary and center diagonal
		if(n % 2 == 0) return x+y;           
        //odd size square matrix
		return x+y-mat[n/2][n/2]; // subtracts center element
	}
};
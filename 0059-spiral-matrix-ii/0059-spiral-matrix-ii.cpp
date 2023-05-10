class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>>mat(n,vector<int>(n));
		int maxr=n-1,maxc=n-1,minr=0,minc=0;
		int k=1;
		while(k<=n*n){
//          upper wall
			for(int j=minc;j<=maxc;j++){
				int i=minr;
				mat[i][j]=k;
				k++;
			}
			minr++;
//          right wall
			for(int i=minr;i<=maxr;i++){
				int j=maxc;
				mat[i][j]=k;
				k++;
			}
			maxc--;
//          lower wall
			for(int j=maxc;j>=minc;j--){
				int i=maxr;
				mat[i][j]=k;
				k++;
			}
			maxr--;
//          left wall
			for(int i=maxr;i>=minr;i--){
				int j=minc;
				mat[i][j]=k;
				k++;
			}
			minc++;
		}
		return mat;
	}
};
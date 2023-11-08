 class Solution {
	public:
		void gameOfLife(vector<vector<int>>& b) {
			int m=b.size();
			int n=b[0].size();
			vector<vector<int>> ans(m,vector<int>(n,0));
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					int temp=0;
					if(i-1>=0){
						if(j-1>=0) temp+=b[i-1][j-1];
						if(j+1<n) temp+=b[i-1][j+1];
						temp+=b[i-1][j];
					}    
					if(i+1<m){
						if(j-1>=0) temp+=b[i+1][j-1];
						if(j+1<n) temp+=b[i+1][j+1];
						temp+= b[i+1][j];
					}  
					if(j-1>=0) temp+=b[i][j-1];
					if(j+1<n) temp+=b[i][j+1];
					if(b[i][j]) ans[i][j]= !(temp<2 || temp>3);
					else ans[i][j]= temp==3;
				}
			}
			b=ans;
		}
	};
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        
        int m=mat.length,n=mat[0].length;
		
		// first calculating prefix sum column-wise
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j] += mat[i][j-1];
            }
        }
		
		// row-wise
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                mat[i][j]+=mat[i-1][j];
            }
        }
        int[][] ans = new int[m][n];
        
		// Then applying sliding window approach
		// For ex. Take a matrix where m = 5, n=5 and k=2. Then try to apply this approach. 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    int temp = mat[min(k,m-1)][min(j+k,n-1)];
                    ans[i][j] = (j-k)<=0 ? temp : temp - mat[min(k,m-1)][j-k-1];
                    continue;
                }
                if(j==0){
                    int temp = mat[min(i+k,m-1)][min(k,n-1)];
                    ans[i][j] = (i-k)<=0 ? temp : temp - mat[i-k-1][min(k,n-1)];
                    continue;
                }
                int temp = mat[min(i+k,m-1)][min(j+k,n-1)];
                
                if(i-k>0){
                    temp -= mat[i-k-1][min(j+k,n-1)];
                }
                if(j-k>0){
                    temp -= mat[min(i+k,m-1)][j-k-1];
                }
                if(i-k>0 && j-k>0){
                    temp+=mat[i-k-1][j-k-1];
                }
                ans[i][j] = temp;
            }
        }
        return ans;
    }
    
    public int min(int a,int b){
        return Math.min(a,b);
    }
}
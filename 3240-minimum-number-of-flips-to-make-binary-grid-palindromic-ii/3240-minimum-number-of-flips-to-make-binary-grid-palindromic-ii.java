class Solution {
    public int minFlips(int[][] grid) {
        
        int n=grid.length,m=grid[0].length;
        int min=0;
        
        if(n%2!=0 && m%2!=0 && grid[n/2][m/2]==1){min++;}
        
        for(int i=0;i<n/2;i++){
            
            for(int j=0;j<m/2;j++){
                
                int c1=0;
                int e1=grid[i][j];
                int e2=grid[n-i-1][j];
                int e3=grid[i][m-j-1];
                int e4=grid[n-i-1][m-j-1];
                
                if(e1==1){c1++;}
                if(e2==1){c1++;}
                if(e3==1){c1++;}
                if(e4==1){c1++;}
                
                if(c1>4-c1){min+=(4-c1);}
                else{min+=c1;}
                
                
            }
            
        }
        
        
        if(n%2==0 && m%2==0){return min;}
        
        int go=0,gm=0,gz=0;
        if(n%2!=0){
            int i=(n/2);
            int j=0,k=m-1;
            while(j<k){
                if(grid[i][j]==0 && grid[i][k]==0){gz++;}
                else if(grid[i][j]==1 && grid[i][k]==1){go++;}
                else{gm++;}
                j++;k--;
            }
        }
        
        if(m%2!=0){
            int col=(m/2);
            int j=0,k=n-1;
            while(j<k){
                if(grid[j][col]==0 && grid[k][col]==0){gz++;}
                else if(grid[j][col]==1 && grid[k][col]==1){go++;}
                else{gm++;}
                j++;k--;
            }
        }
        
        if(go*2%4==0 || gm!=0){return min+gm;}
        
        
        return min+2;
        
        
    }
}
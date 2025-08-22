class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> rsum(n,0);
        vector<int> csum(m,0);
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=0;j<m;j++){
                t+=grid[i][j];
            }
            rsum[i]=t;
        }
        for(int i=0;i<m;i++){
            int t=0;
            for(int j=0;j<n;j++){
                t+=grid[j][i];
            }
            csum[i]=t;
        }
        int leftr=-1;
        int rightr=-1;
        int leftc=-1;
        int rightc=-1;
        for(int i=0;i<n;i++){
            if(rsum[i]>0){
                leftr=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(rsum[i]>0){
                rightr=i;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(csum[i]>0){
                leftc=i;
                break;
            }
        }
        for(int i=m-1;i>=0;i--){
            if(csum[i]>0){
                rightc=i;
                break;
            }
        }
        return (rightc-leftc+1)*(rightr-leftr+1);


        
    }
};
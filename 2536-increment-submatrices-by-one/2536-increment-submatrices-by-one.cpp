class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> tmp(n,vector<int>(n,0)); 
        
        for(auto x:queries){
            for(int i=x[0];i<=x[2];i++) {
                tmp[i][x[1]]+=1;
                if(x[3]+1<n) tmp[i][x[3]+1]-=1;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                tmp[i][j] += tmp[i][j-1];
            }
        }
        
        return tmp;
    }
};
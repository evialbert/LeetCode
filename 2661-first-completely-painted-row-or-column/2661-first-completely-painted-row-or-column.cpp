class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int,pair<int,int>> mp;
        for(int i= 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        
        vector<int> colCount(m,0);
        vector<int> rowCount(n,0);
        int ans = INT_MAX;
        for(int i = 0; i<m*n; i++){
            auto pr = mp[arr[i]];
            colCount[pr.second]++;
            rowCount[pr.first]++;
        
            if(colCount[pr.second] == n && ans > i){
                ans = i;
                break;
            }
            
            if(rowCount[pr.first] == m && ans > i){
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>arr;
        vector<int>index;
        for(int i =0;i<n;i++){
            int c = 0;
            for(int j =0;j<m;j++){
                if(grid[i][j] ==0){
                    c++;
                }
            }
            if(c == m){
                return {i};
            }
            if(c != 0){
                arr.push_back(grid[i]);
                index.push_back(i);
            }
        }
 
        
        for(int i =0;i<arr.size();i++){
            
            for(int j = i+1;j<arr.size();j++){
                  bool flag = true;
                 vector<int>temp = arr[i];
                for(int k = 0;k<m;k++){
                    temp[k] += arr[j][k];
                    if(temp[k]>=2){
                        cout<<temp[k]<<" ";
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return {index[i],index[j]};
                }
            }
        }
   
        return {};
    }
};
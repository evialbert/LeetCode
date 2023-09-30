class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        map<int, int> result;
        
        for(int i = 0; i < matrix.size(); i++){
            int min = (*min_element(matrix[i].begin(), matrix[i].end()));
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == min){
                    result[matrix[i][j]] = j;
                }
            }
        }
        
        bool flag = true;
        for(auto p : result){
            flag = true;
            for(int i = 0; i < matrix.size(); i++){
                if(matrix[i][p.second] > p.first) { flag = false; break; }
            }
            if(flag) ans.push_back(p.first);
        }
        
        return ans;
    }
};
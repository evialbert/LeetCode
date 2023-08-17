class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        for(int i = 0;i<arr.size();i++){
            for(int j = i;j<arr[0].size();j++){
                swap(arr[i][j], arr[j][i]);
            }
        }
        for(int i = 0;i<arr.size();i++){
            for(int j = 0;j<arr[0].size()/2;j++) swap(arr[i][j], arr[i][arr.size()-j-1]);
        }
    }
};
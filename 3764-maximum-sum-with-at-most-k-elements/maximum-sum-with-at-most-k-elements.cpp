class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<int> select;
        for(int i = 0; i < grid.size();i++){
            int times  = limits[i];
            sort(grid[i].begin(), grid[i].end());
            for(int j = grid[i].size() - 1; times > 0 ; j--){
                select.push_back(grid[i][j]);
                times --;
            }
        }
        if(select.size() == k){
            long long sum = 0;
            for(int i = 0; i < select.size();i++){
                sum += select[i];
            }
            return sum;
        }
        sort(select.begin(), select.end());
        long long sum = 0;
        for(int i = select.size() - 1; k > 0; i--){
            sum += select[i];
            k--;
        }
        return sum;
    }
};
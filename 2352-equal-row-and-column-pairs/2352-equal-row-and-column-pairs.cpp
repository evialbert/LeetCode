class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> uMap;
        int m = grid.size(), n = grid[0].size();
        for(auto row : grid){
            string t;
            for(auto ele : row){
                string s = to_string(ele);
                t += (s + ".");
            }
            t.pop_back();
            uMap[t]++;
        }
        int ans=  0;
        for(int i = 0; i < m ; i++){
            string t;
            for(int j = 0; j < n ;j++)
            {
                string s = to_string(grid[j][i]);
                t += (s + ".");
            }
            t.pop_back();
            if(uMap.count(t) >= 1)
                ans += uMap[t];
        }
        return ans;
        
    }
};
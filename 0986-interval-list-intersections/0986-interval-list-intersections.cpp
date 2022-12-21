class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int n = a.size(), m = b.size();
        int i{}, j{};
        while(i<n && j<m){
            int x = max(a[i][0], b[j][0]);
            int y = min(a[i][1], b[j][1]);
            if(x <= y)
                ans.push_back({x,y});
            if(a[i][1] < b[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};
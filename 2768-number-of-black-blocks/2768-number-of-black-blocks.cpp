class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return ((i >= 0 && i < m - 1) && (j >= 0 && j < n - 1));
    }
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> arr(5);
        vector<vector<int>> top_left = {{0,0},{-1,0},{-1,-1},{0,-1}};
        map<pair<int,int>,int> mp;
        for(auto it:coordinates){
            int x = it[0], y = it[1];
            for(auto gt:top_left){
                int adj_x = gt[0] + x, adj_y = gt[1] + y;
                if(isValid(adj_x,adj_y,m,n))
                    mp[{adj_x,adj_y}]++;
            }
        }
        for(auto it:mp)
            arr[it.second]++;
        long sum = 0, total_blocks = (long)(m - 1) * (n - 1);
        for(auto it:arr)
            sum += it;
        arr[0] = total_blocks - sum;
        return arr;
    }
};
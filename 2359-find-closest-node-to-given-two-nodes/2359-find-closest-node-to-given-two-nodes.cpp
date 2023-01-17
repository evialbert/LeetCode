class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> adj[edges.size()];
        for(int i = 0; i < edges.size(); i++) {
            if(edges[i] != -1)
            adj[i].push_back(edges[i]);
        }
        queue<vector<int>> q;
        q.push({node1, 0});
        q.push({node2, 1});
        vector<vector<bool>> vis(edges.size(), vector<bool>(2, false));
        int ans = INT_MAX;
        bool flag= false;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int num = q.front()[0];
                int idx = q.front()[1];
                q.pop();
                vis[num][idx] = true;
                if(vis[num][1 - idx]) {
                    ans = min(ans, num);
                    flag = true;
                }
                for(auto x: adj[num]) {
                    if(!vis[x][idx])
                    q.push({x, idx});
                }
            }
            if(flag) break;
        }
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};
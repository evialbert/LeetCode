class Solution {
public:
    int fun(int u,unordered_map<int,vector<int>> &g,unordered_map<int,int> &vis)
    {
        vis[u] = 1;
        int ans = 0;
        for (auto v : g[u])
        {
            if (vis.find(v) == vis.end())
            {
               ans += 1 + fun(v,g,vis);
            }
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,vector<int>> row;
        unordered_map<int,vector<int>> col;

        for (int i = 0;i<stones.size();i++)
        {
            int r = stones[i][0];
            int c = stones[i][1];
            row[r].push_back(i);
            col[c].push_back(i);
        }

        unordered_map<int,vector<int>> g;

        for (auto it : row)
        {
            auto temp = it.second;
            for (int i = 0;i<temp.size();i++)
            {
                for (int j = i+1;j<temp.size();j++)
                {
                    g[temp[i]].push_back(temp[j]);
                    g[temp[j]].push_back(temp[i]);
                }
            }
        }

        for (auto it : col)
        {
            auto temp = it.second;
            for (int i = 0;i<temp.size();i++)
            {
                for (int j = i+1;j<temp.size();j++)
                {
                    g[temp[i]].push_back(temp[j]);
                    g[temp[j]].push_back(temp[i]);
                }
            }
        }
        int ans = 0;
        unordered_map<int,int> vis;
        for (int i = 0;i<stones.size();i++)
        {
           
            if (vis.find(i) == vis.end())
            {
                ans += fun(i,g,vis);
            }
        }
        return ans;
        
    }
};
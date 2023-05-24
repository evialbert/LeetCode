class Solution {
public:
    vector<pair<int,int>>dp[200];
    vector<int>find(int n,int src,int dist)
    {
        vector<int>dis(n+1,1e9+10);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dis[src]=0;
        vector<int>vis(n+10,0);
        while(pq.size())
        {
            auto [wt,node]=pq.top();
            pq.pop();
            if(vis[node])
            {
                continue;
            }
            vis[node]=1;
            for(auto &[current_node,current_wt]:dp[node])
            {
                if(dis[current_node]>current_wt+wt)
                {
                    dis[current_node]=current_wt+wt;
                    pq.push({dis[current_node],current_node});
                }
            }
        }
        return dis;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) 
    {
        for(auto &it:edges)
        {
            if(it[2]==-1)
            {
                continue;
            }
            dp[it[0]].push_back({it[1],it[2]});
            dp[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist=find(n,src,dest);
        if(dist[dest]<target)
        {
            return {};
        }
       if(dist[dest]==target)
       {
           for(auto &it:edges)
           {
               if(it[2]==-1){
                   it[2]=2e9;
               }
           }
           return edges;
       }
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            if(w==-1)
            {
                edges[i][2]=1;
                dp[u].push_back({v,1});
                dp[v].push_back({u,1});
                vector<int>dis=find(n,src,dest);
                if(dis[dest]<=target)
                {
                    edges[i][2]+=(target-dis[dest]);
                    for(int j=i+1;j<edges.size();j++)
                    {
                        if(edges[j][2]==-1)
                        {
                            edges[j][2]=2e9;
                        }
                    }
                    return edges;
                }
            }
        }
        return {};
    }
};
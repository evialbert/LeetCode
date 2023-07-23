class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto &a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        queue<pair<int,int>> q;
        q.push({1,1});
        vector<pair<int,int>> visited(n+1,{-1,-1});
        visited[1]={0,-1};
        int mint;
        while(q.size()){
            auto [f,first]=q.front();
            q.pop();
            int t;
            if(first==1)
                t=visited[f].first;
            else
                t=visited[f].second;
            if(f==n and visited[n].second!=-1){
                return visited[n].second;
            }
            for(auto &a:adj[f]){
                if(visited[a].second!=-1)
                    continue;
                auto &[at1,at2]=visited[a];
                int nt;
                if((t/change)%2==0)
                    nt=t+time;
                else
                    nt=change*((t/change)+1)+time;
                if(at1==-1){
                    q.push({a,1});
                    at1=nt;
                }else if(at2==-1 and at1!=nt){
                    q.push({a,2});
                    at2=nt;
                }
            }
        }
        return 0;
    }
};
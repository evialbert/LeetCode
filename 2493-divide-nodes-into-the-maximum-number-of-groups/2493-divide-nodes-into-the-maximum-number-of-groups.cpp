class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n+5);
        for(auto&e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int>dis(n+5,n+5);
        queue<int>q;
        vector<int>s(n+5,0);
        for(int i=1;i<=n;++i){
            q.push(i);
            fill(dis.begin(),dis.end(),n+5);
            dis[i]=0;
            int mx=0,mi=i;
            while(!q.empty()){
                int x=q.front();q.pop();
                for(int v:graph[x])if(dis[v]==n+5){
                    dis[v]=dis[x]+1;
                    mx=max(mx,dis[v]);
                    mi=min(mi,v);
                    q.push(v);
                }else if(dis[v]%2!=(dis[x]+1)%2){
                    return -1;
                }
            }
            s[mi]=max(s[mi],mx+1);
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            ans+=s[i];
        }
        return ans;
    }
};
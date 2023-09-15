class DSU{
    public:
    vector<int> size;
    vector<int> parent;
    DSU(int n){
        for(int i=0;i<=n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    void Union(int u ,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pv==pu){
            return;
        }
        if(size[pv] > size[pu]){
                parent[pu] = pv;
                size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
};
class point{
    public:
    int u,v;
    int wt;
    point(int _u,int _v,int _wt){
        u=_u;
        v=_v;
        wt=_wt;
    }
};
class Solution {
    public:
    bool static cmp(point &p1,point &p2){
        return p1.wt < p2.wt;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<point> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back(point(i,j,wt));
            }
        }
        
        int cost=0;
        DSU d(n);
        sort(edges.begin(),edges.end(),cmp);
        // for(auto it : edges){
        //     cout<<it.u<<" "<<it.v<<" "<<it.wt<<" \n";
        // }
        int s=0;
        for(auto edge : edges){
            int u = edge.u;
            int v= edge.v;
            int wt= edge.wt;
            if(d.findParent(u) != d.findParent(v)){
                cost+=wt;
                d.Union(u,v);
                s++;
            }
            if(s==n-1){
                break;
            }
        }
        
        return cost;
    }
};
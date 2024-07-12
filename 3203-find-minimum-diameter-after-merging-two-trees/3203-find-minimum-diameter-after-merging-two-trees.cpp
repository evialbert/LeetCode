class Solution {
public:
  int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int d1 = findDiameter(edges1);
    int d2 = findDiameter(edges2); 
    if(d1 < d2) swap(d1, d2);
    int a = (d1+1)/2;
    int b = d1/2;
    int c = (d2+1)/2 + 1;
    return a + max(b,c);     
  }

  int findDiameter(vector<vector<int>>& edges){
    if(edges.size() == 0) return 0;
    unordered_map<int, vector<int>> g;

    for(auto &e: edges){
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    int start, end;
    for(auto &[k,v] : g)
      if(v.size() == 1){start = k; break;}

    queue<int> q;
    q.push(start);
    vector<int> vis(g.size(), 0);
    while(!q.empty())
      for(int n = q.size(); n != 0; n--){
        int ver = q.front(); q.pop();
        if(vis[ver]) continue;
        vis[ver] = 1;
        end = ver;
        for(auto next: g[ver])
          if(vis[next] == 0) q.push(next);
      }

    q.push(end);
    int wave = -1, n;
    while(!q.empty())
      for(wave++, n = q.size(); n != 0; n--){
        int ver = q.front(); q.pop();
        if(vis[ver] == 0) continue;
        vis[ver] = 0;
        end = ver;
        for(auto next: g[ver])
          if(vis[next] == 1) q.push(next);
      }

    return wave;
  }
};
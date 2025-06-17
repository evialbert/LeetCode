class Solution {
public:
// priority_queue<pair<int,int>>q;
set<int>vis;
    int f(unordered_map<int,list<int>> &mp,int curr){
        vis.insert(curr);
        int ans=0;
        for(auto x:mp[curr]){
            if(vis.find(x)==vis.end()){
            vis.insert(x);
            ans = max(ans,1+f(mp,x));
            }
        }
        // q.push({ans,curr});
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& v) {
        unordered_map<int,list<int>> mp;
        for(int i=0;i<v.size();i++){
            mp[v[i][0]].push_back(v[i][1]);
            mp[v[i][1]].push_back(v[i][0]);
        }

        int deep = f(mp,1) ;
        int mod = 1e9+7;
        int res=1;
        for(int i=0;i<deep-1;i++){
            res = (res * 2 )% mod ;
        }
        return res;



    }
};
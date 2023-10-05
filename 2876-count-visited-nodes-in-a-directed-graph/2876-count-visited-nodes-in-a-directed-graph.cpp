class Solution {
public:
   int tim[100000]={0};
    int t = 0;
    vector<int>ans;
    int dfs(int &cycleNode,bool &flag,int node,vector<int>&edges){
        if(ans[node]) return ans[node];
        if(tim[node]){cycleNode = node;flag =1;return t-tim[node]+1;}
        tim[node] = ++t;
        int res = dfs(cycleNode,flag,edges[node],edges);
        ans[node]= res + !flag;
        if(cycleNode==node) flag = 0;
        return ans[node];
    }
    
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        ans.resize(n,0);
        for(int i = 0;i<n;i++){
            if(ans[i]) continue;
            int cycleNode = -1;bool flag = 0;
            dfs(cycleNode,flag,i,edges);
        }
        return ans;
    }
};
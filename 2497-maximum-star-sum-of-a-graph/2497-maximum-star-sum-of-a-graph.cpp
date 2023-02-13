class Solution {
public:

    int dfs(vector<vector<int>>&v,int s,int k,vector<int>&vl){
        int n=v[s].size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(vl[v[s][i]]);
        }
        int a=0;
        for(int i=0;i<min(k,n);i++){
            int b=pq.top();
            pq.pop();
            if(b<0)continue;
            a+=b;
        }
        return a+vl[s];
    }

    int maxStarSum(vector<int>&vl, vector<vector<int>>&e, int k) {
        int n=vl.size();
        vector<vector<int>>v(n);
        for(int i=0;i<e.size();i++){
            v[e[i][0]].push_back(e[i][1]);
            v[e[i][1]].push_back(e[i][0]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int a=dfs(v,i,k,vl);
            ans=max(ans,a);
        }
        return ans;
    }
};
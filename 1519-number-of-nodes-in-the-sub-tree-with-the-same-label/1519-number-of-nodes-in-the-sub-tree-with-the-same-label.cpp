class Solution {
public:
    void merge(vector<int> &freq,vector<int> &curr)
    {
        for(int i=0;i<26;i++)
        {
            freq[i]+=curr[i];
        }
    }
    vector<int> cal(int u,int par,vector<int> graph[],vector<int> &ans,string& labels)
    {
        vector<int> freq(26,0);
        freq[labels[u]-'a']++;
        for(auto x:graph[u])
        {
            if(x!=par)
            {
                vector<int> curr=cal(x,u,graph,ans,labels);
                merge(freq,curr);
            }
        }
        ans[u]=freq[labels[u]-'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> graph[n];
        vector<int> ans(n,0);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        cal(0,-1,graph,ans,labels);
        return ans;
    }
};
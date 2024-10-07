class Solution {
public:map<int,int> p,pp; bool b=0;
    void t(int k,int n,vector<vector<int>> &a,vector<int> &v)
    {
        p[k]++;
        v[k]=1;

        for(auto i : a[k]) {
            if(!v[i]) t(i,n,a,v);
        }
    }
    void tt(int i,int n,vector<vector<int>> &a,vector<int> &v)
    {
        if(v[i]) return ;
        v[i]=1;
        if(p.find(i)!=p.end()) b=1;

        for(auto j : a[i])
        {
            if(!v[j]) tt(j,n,a,v);
        }
        return ;
    } 
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& d) {
        vector<vector<int>> a(n);
        for(auto i : d) a[i[0]].push_back(i[1]);
        vector<int> v(n+1,0),r=v;
        t(k,n,a,v); 

         v=r;pp=p;
        for(int i=0;i<n;i++) 
        if(pp.find(i)==pp.end())
        tt(i,n,a,v);

        vector<int> ans;
        for(int i=0;i<n;i++)
            if(p[i]==0 || b) ans.push_back(i);
        
        return ans;
    }
};
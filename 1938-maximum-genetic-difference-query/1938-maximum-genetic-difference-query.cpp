class Solution {
public:
    struct Node
    {
        int cnt[2];
        Node *child[2];
        Node()
        {
            for(int i=0;i<2;i++)
                cnt[i]=0,child[i]=NULL;
        }
    }*root;
    
    void add(int n)
    {
        Node *now=root;
        for(int i=30;i>=0;i--)
        {
            bool x=(n & (1<<i));
            if(!now->child[x]) now->child[x]=new Node();
            now->cnt[x]++;
            now=now->child[x];
        }
    }
    
    void remove(int n)
    {
        Node *now=root;
        for(int i=30;i>=0;i--)
        {
            bool x=(n & (1<<i));
            now->cnt[x]--;
            if(now->cnt[x]==0)
            {
                now->child[x]=NULL;
                delete(now->child[x]);
                return ;
            }
            now=now->child[x];
        }
    }
    
    int get(int val)
    {
        Node *now=root;
        int ans=0;
        for(int i=30;i>=0;i--)
        {
            bool x=(val & (1<<i));
            if(x)
            {
                if(now->cnt[0])
                    ans|=(1<<i),now=now->child[0];
                else
                    now=now->child[1];
            }
            else
            {
                if(now->cnt[1])
                    ans|=(1<<i),now=now->child[1];
                else
                    now=now->child[0];
            }
        }
        return ans;
    }
    
    
    vector<int> v[100005],ans;
    vector<pair<int,int>> q[100005];
    
    void dfs(int now)
    {
        add(now);
        for(auto to:v[now])
            dfs(to);
        for(auto i:q[now])
            ans[i.second]=get(i.first);
        remove(now);
    }
    
    vector<int> maxGeneticDifference(vector<int>& p, vector<vector<int>>& qu) 
    {
        int n=p.size(),rt;
        for(int i=0;i<n;i++)
            if(p[i]!=-1) v[p[i]].push_back(i);
            else  rt=i;
        for(int i=0;i<qu.size();i++)
            q[qu[i][0]].push_back({qu[i][1],i});
        
        root=new Node();
        ans.resize(qu.size());
        dfs(rt);
        return ans;
    }
};
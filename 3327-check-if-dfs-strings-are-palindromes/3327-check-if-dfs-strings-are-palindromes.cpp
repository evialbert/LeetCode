class Solution {
    typedef long long ll;
    vector<ll> hash,rhash,p,rp;
    vector<vector<int>> adj;
    vector<int> cnt;
    string str="";
    const int mod=1e9+7;
    void dfs(int node,int pre,string &s){
        for(auto i:adj[node]){
            if(i==pre)continue;
            dfs(i,node,s);
            cnt[node]+=cnt[i];
        }
        str.push_back(s[node]);

    }
    void hashing(){
        int n=str.size();
        hash.resize(n);
        rhash.resize(n);
        p.resize(n);
        rp.resize(n);
        ll po=31;
        hash[0]=str[0]-'a'+1;
        rhash[n-1]=str[n-1]-'a'+1;
        p[0]=1;
        rp[n-1]=1;
        for(int i=1;i<n;i++){
            hash[i]=(hash[i-1] + (str[i]-'a'+1)*po)%mod;
            p[i]=po;
            po*=31;
            po%=mod;
        }
        po=31;
        for(int i=n-2;i>=0;i--){
            rhash[i]=(rhash[i+1] + (str[i]-'a'+1)*po)%mod;
            rp[i]=po;
            po*=31;
            po%=mod;
        }
    }
    int r=0;
    vector<bool> ans;
    bool check(int l){
        int n=str.size();
        int mid=(l+r)/2;
        int en=mid-1;
        if((l+r)&1)en++;
        int st=mid+1;
        ll cur1=hash[en];
        cur1-=(l==0?0:hash[l-1]);
        cur1+=mod;
        cur1%=mod;
        ll cur2=rhash[st];
        cur2-=(r==n-1?0:rhash[r+1]);
        cur2+=mod;
        cur2%=mod;
        return ((cur1*rp[r])%mod == (cur2*p[l])%mod);
    }
    void dfs1(int node,int pre){

        for(auto i:adj[node]){
            if(i==pre)continue;
            dfs1(i,node);
        }
        int l=r-cnt[node]+1;
        if(node==10)cout<<l<<" "<<r<<" ";
       // cout<<node<<" "<<l<<" "<<str;
        if(l==r)ans[node]=true;
      else  if(check(l))ans[node]=true;

        r++;
    }
public:
    vector<bool> findAnswer(vector<int>& par, string s) {
        int n=par.size();
        adj.resize(n);
        cnt.resize(n,1);
        ans.resize(n,false);
        for(int i=1;i<n;i++)adj[par[i]].push_back(i);
        for(auto &i:adj)sort(begin(i),end(i));

        dfs(0,-1,s);
        hashing();
        dfs1(0,-1);

        return ans;

    }
};
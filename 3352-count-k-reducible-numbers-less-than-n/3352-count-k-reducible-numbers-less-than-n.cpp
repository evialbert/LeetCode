class Solution {
public:

    int pre[801];
    int mod=1e9+7;
    int get(int n){
          int cnt=0;
          while(n>1){
            n=__builtin_popcount(n);
            cnt++;
            if(pre[n]) return cnt+pre[n];
          }
          return cnt;
    }
    int dp[801][801][3][3];
    int ok(int ind,int tight,int cnt,int prev,string &num,int k){
        if(ind>=num.size()){
              if(cnt==1 && prev==1) return 1;
              return pre[cnt]+1<=k;
        }
        if(dp[ind][cnt][tight][prev+1]!=-1) return dp[ind][cnt][tight][prev+1];
        int ub=(tight)?num[ind]-'0':1;
        int ans=0;
        for(int d=0;d<=ub;d++){
            ans+=ok(ind+1,(tight&(d==ub)),cnt+d,d,num,k);
            ans%=mod;
        }
        return dp[ind][cnt][tight][prev+1]=ans;
    }
    int countKReducibleNumbers(string s, int k) {
        if(s.size()==1) return 0;
        memset(pre,0,sizeof(pre));
        pre[1]=0;
        for(int i=2;i<=800;i++) pre[i]=get(i);
        int cnt1=0;
        memset(dp,-1,sizeof(dp));
        int ans=ok(0,1,0,-1,s,k);
        int extra=(1+pre[count(s.begin(),s.end(),'1')]<=k);
        return ans-1-extra;

    }
};
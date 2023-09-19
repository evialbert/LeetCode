class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int b, vector<vector<int>>& co, vector<int>& st, vector<int>& ct) {
        long long mx=0;
         for(int i=0; i<co.size(); i++) {
             long long l=0,r=1e9;
             long long ans=0;
             while(l<=r) {
                 long long md=(l+r)/2;
                 long long cost=0;
                 for(int j=0; j<st.size(); j++) {
                     if(md*co[i][j]-st[j]>0) {
                         long long x=(md*co[i][j]-st[j])*ct[j];
                         cost+=x;
                     }
                 }
                 if(cost>b) r=md-1;
                 else ans=md,l=md+1;
             }
             mx=max(ans,mx);
         }
        return mx;
    }
};
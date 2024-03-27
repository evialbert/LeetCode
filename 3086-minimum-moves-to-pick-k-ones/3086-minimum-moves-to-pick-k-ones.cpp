class Solution {
public:
    long long minimumMoves(vector<int>& a, int k, int maxChanges) {
        int n = a.size();
        vector<int>v;
        for(int i = 0;i<n;i++){
            if(a[i])v.push_back(i);
        }
        vector<long long>sum(v.size(), 0);
        for(int i = 0;i<v.size();i++){
            sum[i] = v[i] + (i?sum[i-1]: 0);
        }
        long long ret = 1LL<<60;
        int cur = -1;
        int l = 0, r = k - maxChanges-1;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            if(a[i])cnt++;
            long long ans = 0;
            if(cnt>=k){
                ret=min(ret, ans);
                continue;
            }
            if(i&&a[i-1]){
                cnt++;
                ans++;
            }
            if(cnt>=k){
                ret=min(ret, ans);
                continue;
            }
            if(i+1<n&&a[i+1]){
                cnt++;
                ans++;
            }
            if(cnt>=k){
                ret=min(ret, ans);
                continue;
            }
            if(maxChanges + cnt >=k){
                ans += (k-cnt)*2;
                ret=min(ret, ans);
                continue;
            }
            ans = 2*maxChanges;
            int need = k - maxChanges;
            while(r+1<v.size()&&abs(v[r+1]-i)<abs(v[l]-i)){
                l++;
                r++;
            }
            while(cur+1<v.size()&&v[cur+1]<=i)cur++;
            if(cur>=l){
                ans += i * (long long)(cur-l+1) - (sum[cur]-(l?sum[l-1]:0));
            }
            if(cur<r){
                ans += -i * (long long)(r-cur) + sum[r] - (cur==-1?0:sum[cur]);
            }
            ret=min(ret, ans);
        }
        return ret;
    }
};
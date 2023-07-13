class Solution {
typedef long long ll;
#define vi(x) vector<x>
#define pb push_back
public:
    ll n;
    vi(ll)f, s;
    ll bs(const vi(ll)&v, ll tar){
        ll l=0, r=v.size()-1, ans=v.size()-1;
        while(l<=r){
            ll m=l+((r-l)>>1);
            if(v[m]>=tar){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
    void getSeqSum(vi(ll)&arr, const vi(int)&v, ll start, ll end){
        arr.pb(0);
        for(ll i=start;i<end;++i){
            ll sz=arr.size();
            for(ll j=0;j<sz;++j){
                arr.pb(arr[j]+v[i]);
            }
        }
    }
    int minAbsDifference(vector<int>&v, int tar) {
        n=v.size();
        getSeqSum(f, v, 0, n/2), getSeqSum(s, v, n/2, n);
        sort(f.begin(), f.end());
        ll ans=LLONG_MAX;
        for(ll i=0;i<s.size();++i){
            ll in=bs(f, tar-s[i]);
            ans=min(ans, abs(tar-s[i]-f[in]));
            if(in>0){
                ans=min(ans, abs(tar-s[i]-f[in-1]));
            }
        }
        return ans;
    }
};
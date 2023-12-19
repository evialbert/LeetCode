class Solution {
public:
    typedef long long ll;
    int maxFrequencyScore(vector<int>& a, long long k) {
        sort(a.begin(),a.end());

        int n=a.size(),s=0,e=n,ans=1;
        vector<ll> pre(n,0);
        pre[0]=a[0];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+a[i];

        while(s<=e){
            int mid=(s+e)/2;
            bool chk=0;
            for(int i=0,j=0;j<n;j++){
                if(j-i+1==mid){
                    int m=(i+j)/2;
                    ll x=pre[m]-pre[i]+a[i],xl=m-i+1;
                    ll y=pre[j]-pre[m]+a[m],yl=j-m+1;
                    long long p=abs(x-a[m]*xl)+abs(y-a[m]*yl);
                    if(p<=k){
                        chk=1;
                        break;
                    }
                    i++;
                }
            }
            if(chk)ans=mid,s=mid+1;
            else e=mid-1;
        }

        return ans;
    }
};
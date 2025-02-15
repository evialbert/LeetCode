class Solution {
public:
    long long maxScore(vector<int>& arr, int m) {
        long long l=0,r=1e15;
        int n = arr.size();
        long long q=0;
        while(l<=r){
            long long mid = (l+r)/2;
            long long next = 0;
            long long ans = 0;
            for(int i=0;i<n;i++){
                long long h= arr[i];
                if(next>1e10){
                    ans+=next;
                    break;
                }
                long long sum = (next*h) ;
                long long tar = max((long long)0, mid - sum);
                long long req = max((long long)1,(tar+arr[i]-1)/arr[i]);
                next=req-1;
                if(i==n-1){
                    if((tar+arr[i]-1)/arr[i] != 0) ans += req+req-1;
                }
                else 
                ans+=req+req-1;
            }
            if( m < ans){
                q=mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        if(l==0)return 0;
        return l-1;
    }
};
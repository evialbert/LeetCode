class Solution {
public:
    int mySqrt(int x) {
        long long l=1,h=x,mid,ans;
        while(l<=h){
            mid=(l+h)/2;
            long long msq=mid*mid;
            if(msq==x)return mid;
            else if(msq>x){
                h=mid-1;
            }
            else{
                l=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};
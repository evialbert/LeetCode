class Solution {
public:
    int arrangeCoins(int n) {
        int low=0, high=n;
        
        while(low<=high) {
            int mid=low+(high-low)/2;
            long sum=1ll*mid*(mid+1)/2;
            if(sum == n)
                return mid;
            else if(sum > n)
                high=mid-1;
            else
                low=mid+1;
        }
        return high;
    }
};
class Solution {
public:
    #define ll long long
    long long incremovableSubarrayCount(vector<int>& nums) {
        ll n=nums.size();
        ll l,r;
        for(l=1;l<n;++l){
            if(nums[l] <= nums[l-1]){
                break;
            }
        }
        
        for(r=n-1;r>=1;r--){
            if(nums[r] <= nums[r-1]) {
                break;
            }
        }

        l--;
        if(l>=r) return n*(n+1)/2;
        ll cnt = n-r+1;
        ll i=0,j=r;
        while(i<=l and j<n){
            if(nums[j] > nums[i]) cnt += n-j+1,i++;
            else j++;
        }
        return cnt + l-i+1;
    }
};
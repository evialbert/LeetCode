class Solution {
public:
    long long subarray(long long n){
        return n*(n+1)/2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long s=nums.size();
        long long count=0;
        long long ans=0;   
        for(auto x:nums){
            if(x==0) count++;
            else{
                ans=ans+subarray(count);
                count=0;
            }
        }
        ans=ans+subarray(count);
        return ans;
    }
};
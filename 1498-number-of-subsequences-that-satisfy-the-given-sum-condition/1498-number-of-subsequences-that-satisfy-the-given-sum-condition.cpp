class Solution {
public:
    int mod = 1e9 + 7;
    int power(int n){
        //This is binary exponentiation gives 2^n because our ans in this step is nC0 + nC1 + ........ + nCn = 2^n
        long long ans = 1,base = 2;
        while(n){
            if(n&1) ans = (ans*base)%mod;
            base = (base * base) % mod;
            n = n>>1; // n = n/2
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size() - 1;
        long long ans = 0;
        while(i<=j){
            if(nums[i] + nums[j] <= target){
                ans = (ans + power(j-i)) % mod;
                i++;
            }
            else {
                if(2*nums[j] <= target) ans++;
                j--;
            }
        }
        return ans;
    }
};
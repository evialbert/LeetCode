class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
           int cnt = 0;
        
           int n = nums.size();
        
        for(int i=0; i<n; i++){
            int c  = 0;

            for(int j=i; j<n; j++)
            {
                c = __gcd(c, nums[j]);

                if(c == k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
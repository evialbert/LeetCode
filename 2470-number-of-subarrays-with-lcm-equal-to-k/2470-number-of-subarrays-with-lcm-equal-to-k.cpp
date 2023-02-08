class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        
        int n = nums.size() , ans = 0;
        int i = 0 ;

        while(i < n){
            int curr_lcm = 1 , j = i++;
            while(j<n && k%nums[j] == 0){
                curr_lcm = lcm(curr_lcm,nums[j++]);
                if(k == curr_lcm) ans++;
            }
        }

        return ans;
    }
};
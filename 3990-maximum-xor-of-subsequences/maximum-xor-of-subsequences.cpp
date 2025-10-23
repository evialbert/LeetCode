class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {

        int n = nums.size();

        vector<int> basis;
        for(auto x: nums){
            for(auto el: basis){
                x = min(x, x^el);
            }
            if(x != 0) basis.push_back(x);
        }
        sort(basis.rbegin(), basis.rend());

        int ans = 0;
        for(auto el: basis){
            ans = max(ans, el^ans);
        }
        return ans;

        
    }
};
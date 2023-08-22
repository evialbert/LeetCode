class Solution {
public:
    
    int fun(vector<int>&v, int k) {
        int ans =1 ;
        int n = v.size() ;
        int i=0, j=0 , count =0;
        while (i<n) {
            while (v[i] - v[j]- count > k) {j++; count -- ;}
            count ++ ;
            ans = max(ans, i-j+1) ;
            i++;
        }
        return ans ;
    }
    
    
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans =0 ;
        map<int, vector<int>> m ;
        for (int i=0; i<n; i++) m[nums[i]].push_back(i) ;
        for (auto &[x,v] : m) ans = max(ans, fun(v,k)) ;
        return ans ;
    }
};
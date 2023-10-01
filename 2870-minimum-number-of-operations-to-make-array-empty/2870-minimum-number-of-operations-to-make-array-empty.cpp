class Solution {
public:
    int solve(int n){
        if(n == 1) return -1 ;
        if(n%3 == 0) return n/3 ;
        if(n%3 == 2) return n/3 + 1 ;
        return ((n/3)-1) + 2 ;
    }
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp ;
        for(auto x : nums) mp[x]++ ;
        
        int ans = 0 ;
        for(auto x : mp){
            int temp = solve(x.second) ;
            if(temp == -1) return -1 ;
            else ans += temp ;
        }
        return ans ;
    }
};
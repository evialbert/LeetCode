class Solution {
public:
int findMaxK(vector<int>& nums) {
    unordered_map<int,int> mp;
    
    int ans = -1;
    
    for( auto i : nums ){
        mp[i]++;
    }
    
    for( auto i : nums ){
        if( i>0 && mp.find(-1*i) != mp.end() ){
            ans = max( ans, i );
        }
    }
    
    return ans;
}
};
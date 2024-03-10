class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> v;
        long long sum = 0;
        
        
        for(auto x : nums){
            sum+=x;
            v.push_back((x^k)-x);
        }
        
        sort(v.rbegin(), v.rend());
        
        for(int i=0;i<n-1;i+=2){
            if(v[i]+v[i+1] > 0){
                sum+=(v[i]+v[i+1]);
            }
        }
        
        return sum;
        
    }
};
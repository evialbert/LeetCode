class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n,0);
        for(int i=0 ; i<queries.size() ; i++){
            int s = queries[i][0]; int e = queries[i][1];
            diff[s] += 1;
            if(e+1<n) diff[e+1] -= 1;
        }
        
        int prefixSum = 0;
        for(int i=0 ; i<n ; i++){
            prefixSum += diff[i];
            diff[i] = prefixSum;
        }

        for(int i=0 ; i<n ; i++){
            if(nums[i]>diff[i]){
                return false;
            }
        }
        return true;
    }
};
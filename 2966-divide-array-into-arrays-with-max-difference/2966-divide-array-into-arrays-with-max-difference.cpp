class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans ;
        int n = nums.size();
        for(int i=0, j = 2; i==j-2 && j<n; i +=3, j+=3){
            if(nums[i] + k >= nums[j]){
                ans.push_back({nums[i], nums[i+1], nums[j]});
            }else {
                return {};
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>ans;

        if(nums.size() == 1 && nums[0] == target)
            return{0,0};
        
        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == target){
                ans.push_back(i);
            }
        }
        int n = ans.size();
        if(n > 0)
            return {ans[0],ans[n - 1]};
        else
            return {-1,-1};

    }
};
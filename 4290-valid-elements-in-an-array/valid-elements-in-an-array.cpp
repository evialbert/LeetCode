class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            bool greaterThanLeft = true;

            // checking that nums[i] is strickly greater than left of element
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) {
                    greaterThanLeft = false;
                    break;
                }
            }

            bool greaterThanRight = true;
            // checking that nums[i] is strickly greater than right element
            // only checking is the nums[i] is invalid in the left
            if (!greaterThanLeft) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[i] <= nums[j]) {
                        greaterThanRight = false;
                        break;
                    }
                }
            }

            // if nums[i] is valid for left or the right one then we are pushing it in the resulting array
            if(greaterThanLeft || greaterThanRight){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
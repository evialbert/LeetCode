class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int x = nums[i] + nums[j];
                
                //binary search
                int low = j + 1, high = nums.size() - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (x > nums[mid]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    } 
                }
                count += (low - 1) - (j + 1) + 1;
                               
            }
                
        }
        return count;
    }
};
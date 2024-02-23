class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int, int>maxFor;
        int maxSize = 0;
        for(int i = n - 1; i >= 0; --i){
            if(maxFor.find(nums[i] + 1) == maxFor.end()){
                maxFor[nums[i]] = 1;
            }
            else{
                maxFor[nums[i]] = 1 + maxFor[nums[i] + 1];
            }

            if(maxFor.find(nums[i] + 2) == maxFor.end()){
                maxFor[nums[i] + 1] = 1;
            }
            else{
                maxFor[nums[i] + 1] = 1 + maxFor[nums[i] + 2];
            }

            maxSize = max(maxSize, maxFor[nums[i]]);
            maxSize = max(maxSize, maxFor[nums[i] + 1]);
        }
        return maxSize;
    }
};
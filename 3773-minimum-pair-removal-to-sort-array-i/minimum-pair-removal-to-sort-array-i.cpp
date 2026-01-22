class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while(true){
            // 1) Check if sorted.
            bool isSorted = true;

            for(int i = 0; i < nums.size() - 1;i++){
                if(nums[i] > nums[i+1]){
                    isSorted = false;
                }
            }
            
            if(isSorted) return operations;

            // 2) Find min pair.
            int minSum = INT_MAX;
            int index;

            for(int i = 0; i < nums.size() - 1; i++){
                int currentSum = nums[i] + nums[i+1];
                if(minSum > currentSum){
                    minSum = currentSum;
                    index = i;
                }
            }

            // 3) Replace and merge.
            nums[index] = minSum;
            nums.erase(nums.begin() + index + 1);
            operations++;
        }
    }
};
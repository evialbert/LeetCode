class Solution {
    void insert(vector<int>& sortedArray, int value) {
        auto it = lower_bound(sortedArray.begin(), sortedArray.end(), value);
        sortedArray.insert(it, value);
    }

    int greaterCount(vector<int>& arr, vector<int>& sortedArray, int value) {
        auto it = upper_bound(sortedArray.begin(), sortedArray.end(), value);
        int count = distance(it, sortedArray.end());
        return count;
    }

public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1 = {nums[0]}, arr2 = {nums[1]};
        vector<int> sortedArr1 = arr1, sortedArr2 = arr2;

        for (int i = 2; i < nums.size(); i++) {
            int g1 = greaterCount(arr1, sortedArr1, nums[i]);
            int g2 = greaterCount(arr2, sortedArr2, nums[i]);

            if (g1 > g2) {
                arr1.push_back(nums[i]);
                insert(sortedArr1, nums[i]);
            } else if (g1 < g2) {
                arr2.push_back(nums[i]);
                insert(sortedArr2, nums[i]);
            } else {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]);
                    insert(sortedArr1, nums[i]);
                } else if (arr1.size() > arr2.size()) {
                    arr2.push_back(nums[i]);
                    insert(sortedArr2, nums[i]);
                }
            }
        }

        int index = 0;
        for (int i : arr1)
            nums[index++] = i;
        for (int i : arr2)
            nums[index++] = i;

        return nums;
    }
};
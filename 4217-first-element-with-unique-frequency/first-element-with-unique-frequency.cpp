class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> count;

        for (int i = 0; i < n; i++)
            freq[nums[i]]++;

        for (int i = 0; i < freq.size(); i++) {
            count[freq[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (count[freq[nums[i]]] == 1)
                return nums[i]; //return the first one asked
        }
        return -1;
    }
};
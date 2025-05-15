class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<pair<int, int>> arr;

        // Step 1: Pair each number with its index
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        // Step 2: Sort by value to process smaller numbers first
        sort(arr.begin(), arr.end());

        set<int> st; // Keeps track of all used indices
        st.insert(nums.size()); // Sentinel value to simplify boundary checks

        int count = 0; // Total operations

        // Step 3: Iterate over sorted values
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i].first;
            int lastUsedIndex = -1;

            // Skip zeroes (already 0)
            if (val == 0) {
                st.insert(arr[i].second);
                continue;
            }

            // Step 4: Process all positions having the same value
            while (i < arr.size() && arr[i].first == val) {
                int index = arr[i].second;

                // Find first used index >= current index
                auto itr = st.lower_bound(index);

                // If current index < last used boundary, we can process it
                if (*itr > lastUsedIndex) {
                    count++; // New operation
                    lastUsedIndex = *itr;
                }

                st.insert(index); // Mark index as used
                i++;
            }

            i--; // Adjust for outer loop increment
        }

        return count;
    }
};
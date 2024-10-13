class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        // Min-heap to store {value, {row, column}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int mini = 1e9, maxi = -1e9;

        // Initialize the heap with the first element of each list
        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            pq.push({nums[i][0], {i, 0}});
        }

        // Best range found so far
        int ansMin = mini;
        int ansMax = maxi;
        int diff = maxi - mini;

        // Process until we can't extend all lists
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int miniVal = it.first;  // Current smallest element
            int row = it.second.first;  // Which list this element belongs to
            int col = it.second.second; // Which element in the list

            // If the current range is smaller, update the answer
            if (maxi - miniVal < diff) {
                ansMin = miniVal;
                ansMax = maxi;
                diff = maxi - miniVal;
            }

            // If there are more elements in the same list, push the next one into the heap
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                pq.push({nextVal, {row, col + 1}});
                maxi = max(maxi, nextVal);
            } else {
                // If any list is exhausted, we can't include all lists in the range anymore
                break;
            }
        }

        return {ansMin, ansMax};
    }
};
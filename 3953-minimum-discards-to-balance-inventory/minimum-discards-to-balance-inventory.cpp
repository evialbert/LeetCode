class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        int n = arr.size();
        vector<int> active(n + 1, 1);
        unordered_map<int, int> freq;
        int removed = 0;

        for (int i = 0; i < n; i++) {
            if (freq[arr[i]] >= m) {
                active[i] = 0;
                removed++;
            } else {
                freq[arr[i]]++;
            }

            if (i + 1 >= w && (active[i - w + 1] == 1)) {
                    freq[arr[i - w + 1]]--;
                
            }
        }
        return removed;
    }
};
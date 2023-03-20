class Solution {
public:
    int cumW[10000], total;
    Solution(vector<int>& w) {
        // initialising random seeder
        srand(time(NULL));
        // populating the cumulative weights vector
        cumW[0] = w[0];
        for (int i = 1; i < w.size(); i++) cumW[i] = cumW[i - 1] + w[i];
        total = cumW[w.size() - 1];
        // adding values to cumW to make binary search work
        for (int i = w.size(); i < 10000; i++) cumW[i] = INT_MAX;
    }
    
    int pickIndex() {
        return upper_bound(begin(cumW), end(cumW), rand() % total) - begin(cumW);
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
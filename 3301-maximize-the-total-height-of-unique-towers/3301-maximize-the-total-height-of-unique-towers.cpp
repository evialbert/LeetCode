class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {

        sort(maximumHeight.rbegin(), maximumHeight.rend());

        long long ans = 0;
        int current_height = 1e9 + 1;

        for (int i = 0; i < maximumHeight.size(); i++) {

            current_height = min(current_height - 1, maximumHeight[i]);

            if (current_height <= 0) {
                return -1;
            }

            ans += current_height;
        }

        return ans;
    }
};
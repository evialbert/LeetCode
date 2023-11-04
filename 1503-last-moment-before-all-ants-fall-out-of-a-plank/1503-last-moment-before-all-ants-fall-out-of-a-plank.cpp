class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_time = 0;
        for (auto i : left) {
            max_time = max<int>(i, max_time);
        }
        for (auto i : right) {
            max_time = max<int>(n-i, max_time);
        }
        return max_time;
    }
};
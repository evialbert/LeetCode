class Solution {
public:
    int minSensors(int n, int m, int k) {
        return ((n + 2*k) / (2*k + 1)) * ((m + 2*k) / (2*k + 1));
    }
};
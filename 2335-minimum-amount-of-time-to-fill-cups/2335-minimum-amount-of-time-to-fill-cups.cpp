class Solution {
public:
    int fillCups(vector<int>& a) {
        int sum = a[0]+a[1]+a[2];
        int maxValue = max(a[0], max(a[1], a[2]));
        return max(maxValue, (sum+1)/2);
    }
};
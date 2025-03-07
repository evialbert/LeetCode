class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        int lb = bounds[0][0], up = bounds[0][1];
        int diff = 0;
        for(int i=1; i<n; i++){
            diff = original[i] - original[i-1];
            lb = lb + diff;
            up = up + diff;
            lb = max(lb, bounds[i][0]);
            up = min(up, bounds[i][1]);
        }
        return (up-lb+1) >=0 ? up - lb + 1 : 0;
    }
};
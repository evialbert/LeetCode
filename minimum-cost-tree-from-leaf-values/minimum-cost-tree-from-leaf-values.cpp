class Solution {
private:
    int getMax(vector<int> &a, int i, int j) {
        if(i >= a.size() || i>j) return 0;
        int mx = a[i];
        for(int k = i; k <= j; k++) mx = max(mx, a[k]);
        return mx;
    }
    int compute(vector<int> &a, int i, int j) {
        if(i > j) return 0;
        int mxi = i;
        for(int k = i; k <= j; k++) {
            if(a[k] > a[mxi]) mxi=k;
        }
        int leftVal = compute(a,i,mxi-1);
        int rightVal = compute(a,mxi+1,j);
        int mx = a[mxi];
        return leftVal + rightVal + mx * getMax(a,i,mxi-1) + mx * getMax(a,mxi+1,j);
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        return compute(arr, 0, arr.size()-1);
    }
};
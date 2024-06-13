class Solution {
public:
    int numberOfChild(int n, int k) {
        int t=(k/(n-1));
        int m= (t%2==0)? (0+(k%(n-1))):((n-1)-(k%(n-1)));
        return m;
    }
};
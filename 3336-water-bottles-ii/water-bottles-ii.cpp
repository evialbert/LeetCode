class Solution {
public:
    static int maxBottlesDrunk(int n, int k, int i=0) {
        return ((n<k)?0:(1+maxBottlesDrunk(n-k+1, k+1, i+1)))+(i==0?n:0);
    }
};